#include "TimingVisualiser_AnimNode.h"

//#include UE_INLINE_GENERATED_CPP_BY_NAME (TimingVisualiser_AnimNode)
//-------------------------------------------------------------------------------------------------------------
FTimingVisualiser_AnimNode::FTimingVisualiser_AnimNode() : Super ()
{
	//TestBoneName = FName(TEXT("head"));
	MinVelocity = 0.1f;
	MinAcceleration = 0.1f;
	VelocityArrowMagnitude = 3.0f;
	AccelerationArrowMagnitude = 3.0f;
	CachedFramesNumber = 8;
	DirectionThreshold = -0.75f;
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	// Initialize the asset or actor that owns this node
	Super::Initialize_AnyThread(Context);
	//FAnimNode_Base::Initialize_AnyThread(Context);
	OwningActor = Context.AnimInstanceProxy->GetSkelMeshComponent()->GetOwner();
	SkelMeshComponent = Context.AnimInstanceProxy->GetSkelMeshComponent();
	SkelMesh = SkelMeshComponent->GetSkinnedAsset();
	RefSkeleton = SkelMesh->GetRefSkeleton();
	iBonesCount = RefSkeleton.GetRawBoneNum();
	BasePose.Initialize(Context);

}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	Super::CacheBones_AnyThread(Context);
	//FAnimNode_Base::CacheBones_AnyThread(Context);
	BasePose.CacheBones(Context);
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::Update_AnyThread(const FAnimationUpdateContext& Context)
{
    Super::Update_AnyThread(Context);

    TArray<BoneMotionData> NewFrameBoneMotionData;  // new empty array for the new frame
    MotionDataArrays.Insert(NewFrameBoneMotionData, 0); // insert the new frame at the beginning of the cached motion data array
    if (MotionDataArrays.Num() > CachedFramesNumber)   // Check if the cached motion data array has more than CachedFrames number of frames
    {
		MotionDataArrays.RemoveAt(MotionDataArrays.Num() - 1); // Delete the last element of the cached motion data array
    }

    BasePose.Update(Context);
    GetEvaluateGraphExposedInputs().Execute(Context);
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::GatherDebugData(FNodeDebugData& DebugData)
{
	BasePose.GatherDebugData(DebugData);
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output)
{
    // Implement your custom evaluation logic here
	Super::EvaluateComponentSpace_AnyThread(Output);
	BasePose.EvaluateComponentSpace(Output);
	//GEngine->AddOnScreenDebugMessage(-1, 0.03f, FColor::Red, FString::Printf(TEXT("MSG from EvaluateComponentSpace_AnyThread")));
	GetBoneMotionDataAtFrame(Output);
	if (bDrawVelocities) DrawVelocities(Output);
	if (bDrawAccelerations) DrawAccelerations(Output);
	if (bDrawCounterForces) DrawCounterForces(Output);
}
//-------------------------------------------------------------------------------------------------------------
//void FTimingVisualiser_AnimNode::Evaluate_AnyThread(FPoseContext& Output)
//{
//	// Implement your custom evaluation logic here
//	GEngine->AddOnScreenDebugMessage(-1, 0.03f, FColor::Red, FString::Printf(TEXT("MSG from Evaluate_AnyThread")));
//	// Modify the pose as needed
//}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::GetBoneMotionDataAtFrame(FComponentSpacePoseContext& Output)
{
	FTransform ComponentTransform = SkelMeshComponent->GetComponentTransform();
	FTransform BoneTransform;
	if (iBonesCount)
	{
		for (int curBoneIndex = 0; curBoneIndex < iBonesCount; curBoneIndex++)
		{	
			BoneMotionData curBoneData;
			curBoneData.BoneIndex = curBoneIndex;
			curBoneData.BoneName = RefSkeleton.GetBoneName(curBoneIndex);
			BoneTransform = Output.Pose.GetComponentSpaceTransform(FCompactPoseBoneIndex(curBoneIndex));
			curBoneData.Position = ComponentTransform.TransformPosition(BoneTransform.GetLocation());	// Transform the bone's location to world space
			curBoneData.Velocity = FVector(0.0f, 0.0f, 0.0f); //TODO Later
			curBoneData.Acceleration = FVector(0.0f, 0.0f, 0.0f); //TODO Later
			MotionDataArrays[0].Add(curBoneData);
		}
		CalculateVelocity();
		CalculateAcceleration();

	}
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::CalculateVelocity()
{
    for (int boneIndex = 0; boneIndex < iBonesCount; boneIndex++)
    {
        FVector sumVelocity(0.0f, 0.0f, 0.0f);
        int validFrames = 0;
        for (int cachedFrame = 0; cachedFrame < MotionDataArrays.Num() - 1; cachedFrame++)
        {
            if (MotionDataArrays[cachedFrame].IsValidIndex(boneIndex) && MotionDataArrays[cachedFrame + 1].IsValidIndex(boneIndex))
            {
                sumVelocity += (MotionDataArrays[cachedFrame + 1][boneIndex].Position - MotionDataArrays[cachedFrame][boneIndex].Position);
                validFrames++;
            }
        }
        if (validFrames > 0)
        {
            MotionDataArrays[0][boneIndex].Velocity = sumVelocity / validFrames;
            MotionDataArrays[0][boneIndex].Velocity *= -1; // Reverse the direction of the velocity vector
        }
    }
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::CalculateAcceleration()
{
	for (int boneIndex = 0; boneIndex < iBonesCount; boneIndex++)
	{
		FVector sumAcceleration(0.0f, 0.0f, 0.0f);
		int validFrames = 0;
		for (int cachedFrame = 0; cachedFrame < MotionDataArrays.Num() - 2; cachedFrame++)
		{
			if (MotionDataArrays[cachedFrame].IsValidIndex(boneIndex) && MotionDataArrays[cachedFrame + 1].IsValidIndex(boneIndex) && MotionDataArrays[cachedFrame + 2].IsValidIndex(boneIndex))
			{
				sumAcceleration += (MotionDataArrays[cachedFrame + 2][boneIndex].Position - 2.0 * MotionDataArrays[cachedFrame + 1][boneIndex].Position + MotionDataArrays[cachedFrame][boneIndex].Position);
				validFrames++;
			}
		}
		if (validFrames > 0)
		{
			MotionDataArrays[0][boneIndex].Acceleration = sumAcceleration / validFrames;
			//MotionDataArrays[0][boneIndex].Acceleration *= -1; // Reverse the direction of the acceleration vector
		}
	}
}
//-------------------------------------------------------------------------------------------------------------
float FTimingVisualiser_AnimNode::DetectCounterForce(FVector vVelocity, FVector vAcceleration, float AccelerationThreshold, float DotProductDirectionThreshold)
{
	if (vAcceleration.Length() > AccelerationThreshold)
	{
		// a reminder: dot product is magnitude dependent, that's why it's normalized. When dot product is 0, it means they are perpendicular, -1 means they are opposite, 1 means they are in the same direction
		vVelocity.Normalize();
		vAcceleration.Normalize();
		float NormalizedDotProduct = FVector::DotProduct(vVelocity, vAcceleration);
		if (NormalizedDotProduct < DotProductDirectionThreshold) // if the velocity and acceleration are in opposite directions within the threshold
		{
			return NormalizedDotProduct;
		}
	}
	return 0.0f;
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::DebugDrawArrow(FComponentSpacePoseContext& Output, FVector vFrom, FVector vOrientation, float fMagnitude, FColor Color)
{
	// Draw a debug arrow
	FVector vTo = vFrom + vOrientation * fMagnitude;
	UObject* AnimInstanceObject = Output.AnimInstanceProxy->GetAnimInstanceObject();
	DrawDebugDirectionalArrow(AnimInstanceObject->GetWorld(), vFrom, vTo, 2.0f, Color, false, -1, 1, 0.3f);
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::DebugDrawPulsePoint(FComponentSpacePoseContext& Output, FVector vPosition, FColor Color, float fSize)
{
	UObject* AnimInstanceObject = Output.AnimInstanceProxy->GetAnimInstanceObject();
    for (int i = 0; i < 7; i++)
    {
        float duration = 0.075f + i * 0.05f; // Increase duration time
        float radius = 5.0f - i * 0.6f; // Decrease radius
        DrawDebugSphere(AnimInstanceObject->GetWorld(), vPosition, radius, 8, Color, false, duration, 0, 0.75f);
    }
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::DrawVelocities(FComponentSpacePoseContext& Output)
{
	float fDebugDrawDynamicMagnitude = 0.0f;
	for (const BoneMotionData& BoneData : MotionDataArrays[0]) //TODO. it's totally temp, and it needs to make it nice
	{
		float vectorLength = BoneData.Velocity.Length();
		if (vectorLength > fDebugDrawDynamicMagnitude)
		{
			fDebugDrawDynamicMagnitude = vectorLength;
		}
		// GEngine->AddOnScreenDebugMessage(-1, 0.03f, FColor::Red, FString::Printf(TEXT("max magnitude for the draw is: %f"), fDebugDrawDynamicMagnitude));
	}
	for (const BoneMotionData& BoneData : MotionDataArrays[0])
	{
		if (BoneData.Velocity.Length() > MinVelocity)
		{
			if (!ShouldFilterOutByName(BoneData.BoneName)) // Skip the bone if it's in the filter out list
				DebugDrawArrow(Output, BoneData.Position, BoneData.Velocity, (fDebugDrawDynamicMagnitude / BoneData.Velocity.Length()) * VelocityArrowMagnitude, FColor::Yellow);
		}
	}
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::DrawAccelerations(FComponentSpacePoseContext& Output)
{
	float fDebugDrawDynamicMagnitude = 0.0f;
	for (const BoneMotionData& BoneData : MotionDataArrays[0]) //TODO. it's totally temp, and it needs to make it nice
	{
		float vectorLength = BoneData.Acceleration.Length();
		if (vectorLength > fDebugDrawDynamicMagnitude)
		{
			fDebugDrawDynamicMagnitude = vectorLength;
		}
		// GEngine->AddOnScreenDebugMessage(-1, 0.03f, FColor::Red, FString::Printf(TEXT("max magnitude for the draw is: %f"), fDebugDrawDynamicMagnitude));
	}
	for (const BoneMotionData& BoneData : MotionDataArrays[0])
	{
		if (BoneData.Acceleration.Length() > MinAcceleration)
		{
			if (!ShouldFilterOutByName(BoneData.BoneName)) // Skip the bone if it's in the filter out list
				DebugDrawArrow(Output, BoneData.Position, BoneData.Acceleration, (fDebugDrawDynamicMagnitude / BoneData.Acceleration.Length()) * AccelerationArrowMagnitude * 10.0, FColor::Red);
		}
	}
}
//-------------------------------------------------------------------------------------------------------------
void FTimingVisualiser_AnimNode::DrawCounterForces(FComponentSpacePoseContext& Output)
{
	for (const BoneMotionData& BoneData : MotionDataArrays[0])
	{
		float fCounterForce = DetectCounterForce(BoneData.Velocity, BoneData.Acceleration, MinAcceleration, DirectionThreshold);
		if (fCounterForce != 0.0f)
		{
			if (!ShouldFilterOutByName(BoneData.BoneName)) // Skip the bone if it's in the filter out list
				DebugDrawPulsePoint(Output, BoneData.Position, FColor::Orange, FMath::Abs(fCounterForce)*10.0f);
		}
	}
}
//-------------------------------------------------------------------------------------------------------------
bool FTimingVisualiser_AnimNode::ShouldFilterOutByName(FName BoneName)
{
	bool bShouldFilterOut = false;
	for (const FName& FilterOutName : BoneNameFilterOut)
	{
		if (BoneName.ToString().Contains(FilterOutName.ToString()))
		{
			bShouldFilterOut = true;
			break;
		}
	}
	return bShouldFilterOut;
}
//-------------------------------------------------------------------------------------------------------------