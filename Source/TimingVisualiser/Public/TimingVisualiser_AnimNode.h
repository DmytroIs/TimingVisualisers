#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimInstanceProxy.h"
#include "AnimationRuntime.h"
#include "DrawDebugHelpers.h"
#include "Engine/SkeletalMesh.h"
//#include "Components/SkinnedMeshComponent.h"

#include "TimingVisualiser_AnimNode.generated.h"

struct BoneMotionData
{
    int BoneIndex;
    FName BoneName;
    FVector Position;
    FVector Velocity;
    FVector Acceleration;
};

USTRUCT(BlueprintInternalUseOnly)
struct TIMINGVISUALISER_API FTimingVisualiser_AnimNode : public FAnimNode_Base
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links)
    FComponentSpacePoseLink BasePose; //FPoseLink
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    //FName TestBoneName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    int CachedFramesNumber;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    bool bDrawVelocities;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    float VelocityArrowMagnitude;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	float MinVelocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    bool bDrawAccelerations;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    float AccelerationArrowMagnitude;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    float MinAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	bool bDrawCounterForces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	float DirectionThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
    TArray<FName> BoneNameFilterOut;

public:
    // FAnimNode_Base interface
    FTimingVisualiser_AnimNode();
    virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
    virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
    virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
    //virtual void Evaluate_AnyThread(FPoseContext& Output) override;
    virtual void EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output) override;
    virtual void GatherDebugData(FNodeDebugData& DebugData) override;
    // End of FAnimNode_Base interface
    
protected:
    AActor* OwningActor;

private:
    int iBonesCount; // Number of bones in the skeleton
	USkinnedMeshComponent* SkelMeshComponent; // Skinned mesh component
	USkinnedAsset* SkelMesh; // Skinned mesh asset
	FReferenceSkeleton RefSkeleton; // Reference skeleton

    TArray<TArray<BoneMotionData>> MotionDataArrays; // Dynamic UE Array of BoneMotionData for each bone by CachedFramesNumber number of frames

    void DebugDrawArrow(FComponentSpacePoseContext& Output, FVector vFrom, FVector vOrientation, float fMagnitude, FColor Color);
	void GetBoneMotionDataAtFrame(FComponentSpacePoseContext& Output); // Get bone motion data at the given frame
    void CalculateVelocity();
    void DrawVelocities(FComponentSpacePoseContext& Output);
    void CalculateAcceleration();
	void DrawAccelerations(FComponentSpacePoseContext& Output);
	float DetectCounterForce(FVector vVelocity, FVector vAcceleration, float AccelerationThreshold, float DotProductDirectionThreshold);
	void DebugDrawPulsePoint(FComponentSpacePoseContext& Output, FVector vPosition, FColor Color, float fSize);
	void DrawCounterForces(FComponentSpacePoseContext& Output);
    bool ShouldFilterOutByName(FName BoneName);
};
