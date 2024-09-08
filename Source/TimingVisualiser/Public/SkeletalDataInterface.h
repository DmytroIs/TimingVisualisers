// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/SkeletalMeshComponent.h" 
#include "Engine/SkeletalMesh.h"
#include "Rendering/SkeletalMeshRenderData.h"
#include "Rendering/SkeletalMeshLODRenderData.h"
#include "Rendering/SkeletalMeshVertexBuffer.h"
#include "Animation/Skeleton.h"
#include "AnimationRuntime.h"
#include "Rendering/SkinWeightVertexBuffer.h"

#include "SkeletalDataInterface.generated.h"


/**
 * 
 */
UCLASS()
class TIMINGVISUALISER_API USkeletalDataInterface : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

    UFUNCTION(BlueprintCallable, Category = "AAA_SkeletalMeshData")
    static TArray<FVector3f> GetSkinnedMeshVerticesArray(USkeletalMeshComponent* SkeletalMeshComponent);
};
