#include "TimingVisualiser_AnimNode.h"

//#include UE_INLINE_GENERATED_CPP_BY_NAME (TimingVisualiser_AnimNode)

FTimingVisualiser_AnimNode::FTimingVisualiser_AnimNode() : Super ()
{
	//TestBoneName = FName(TEXT("head"));
	MinVelocity = 0.1f;
	ArrowMagnitude = 3.0f;
}

void FTimingVisualiser_AnimNode::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	// Initialize the asset or actor that owns this node
	Super::Initialize_AnyThread(Context);
	//FAnimNode_Base::Initialize_AnyThread(Context);
	OwningActor = Context.AnimInstanceProxy->GetSkelMeshComponent()->GetOwner();
	SkelMeshComponent = Context.AnimInstanceProxy->GetSkelMeshComponent();
	SkelMesh = SkelMeshComponent->GetSkinnedAsset();
	RefSkeleton = SkelMesh->GetRefSkeleton();
	BonesCount = RefSkeleton.GetRawBoneNum();
	BasePose.Initialize(Context);

}

void FTimingVisualiser_AnimNode::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	Super::CacheBones_AnyThread(Context);
	//FAnimNode_Base::CacheBones_AnyThread(Context);
	BasePose.CacheBones(Context);
}

void FTimingVisualiser_AnimNode::Update_AnyThread(const FAnimationUpdateContext& Context)
{
	Super::Update_AnyThread(Context);
	MotionDataArrayCached = MotionDataArrayCurrent;
	MotionDataArrayCurrent.Empty();
	BasePose.Update(Context);
	GetEvaluateGraphExposedInputs().Execute(Context);
}

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
	GetBoneMotionDataAtFrame(Output, 0.0f);
    float fDebugDrawDynamicMagnitude = 0.0f;
	 for (const BoneMotionData& BoneData : MotionDataArrayCurrent) //TODO. it's totally temp, and it needs to make it nice
	 {
	     float vectorLength = BoneData.Velocity.Length();
	     if (vectorLength > fDebugDrawDynamicMagnitude)
	     {
	         fDebugDrawDynamicMagnitude = vectorLength;
	     }
        // GEngine->AddOnScreenDebugMessage(-1, 0.03f, FColor::Red, FString::Printf(TEXT("max magnitude for the draw is: %f"), fDebugDrawDynamicMagnitude));

	 }
	for (const BoneMotionData& BoneData : MotionDataArrayCurrent)
	{
		if (BoneData.Velocity.Length()>MinVelocity)
			DebugDrawArrow(Output, BoneData.Position, BoneData.Velocity, (fDebugDrawDynamicMagnitude/BoneData.Velocity.Length())*ArrowMagnitude);
	}
}
//-------------------------------------------------------------------------------------------------------------
//void FTimingVisualiser_AnimNode::Evaluate_AnyThread(FPoseContext& Output)
//{
//	// Implement your custom evaluation logic here
//	GEngine->AddOnScreenDebugMessage(-1, 0.03f, FColor::Red, FString::Printf(TEXT("MSG from Evaluate_AnyThread")));
//	// Modify the pose as needed
//}

void FTimingVisualiser_AnimNode::DebugDrawArrow(FComponentSpacePoseContext& Output, FVector vFrom, FVector vOrientation, float fMagnitude)
{
	// Draw a debug arrow
	FVector vTo = vFrom + vOrientation * fMagnitude;
	UObject* AnimInstanceObject = Output.AnimInstanceProxy->GetAnimInstanceObject();        
	DrawDebugDirectionalArrow(AnimInstanceObject->GetWorld(), vFrom, vTo, 2.0f, FColor::Yellow, false, -1, 1, 0.3f);
}

void FTimingVisualiser_AnimNode::GetBoneMotionDataAtFrame(FComponentSpacePoseContext& Output, float TimeStamp)
{
	FTransform ComponentTransform = SkelMeshComponent->GetComponentTransform();
	FTransform BoneTransform;
	if (BonesCount)
	{
		for (int curBoneIndex = 0; curBoneIndex < BonesCount; curBoneIndex++)
		{	
			BoneMotionData curBoneData;
			curBoneData.BoneIndex = curBoneIndex;
			BoneTransform = Output.Pose.GetComponentSpaceTransform(FCompactPoseBoneIndex(curBoneIndex));
			curBoneData.Position = ComponentTransform.TransformPosition(BoneTransform.GetLocation());	// Transform the bone's location to world space
			curBoneData.Velocity = FVector(0.0f, 0.0f, 0.0f); //TODO Later
			curBoneData.Acceleration = FVector(0.0f, 0.0f, 0.0f); //TODO Later
			MotionDataArrayCurrent.Add(curBoneData);
		}
		CalculateVelocity();
	}
}

void FTimingVisualiser_AnimNode::CalculateVelocity()
{
    for (int i = 0; i < MotionDataArrayCurrent.Num(); i++)
    {
        if (MotionDataArrayCached.IsValidIndex(i))
        {
            FVector currentPosition = MotionDataArrayCurrent[i].Position;
            FVector cachedPosition = MotionDataArrayCached[i].Position;
            FVector velocity = currentPosition - cachedPosition;
            MotionDataArrayCurrent[i].Velocity = velocity;
        }
    }
}
