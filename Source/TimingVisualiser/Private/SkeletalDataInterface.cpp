// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletalDataInterface.h"

TArray<FVector3f> USkeletalDataInterface::GetSkinnedMeshVerticesArray(USkeletalMeshComponent* SkeletalMeshComponent)
{
	if (!SkeletalMeshComponent || !SkeletalMeshComponent->GetSkeletalMeshAsset())
	{
		return TArray<FVector3f>();
	}
	USkeletalMesh* SkeletalMesh = SkeletalMeshComponent->GetSkeletalMeshAsset();
	FSkeletalMeshRenderData* RenderData = SkeletalMesh->GetResourceForRendering();
	if (!RenderData)
	{
		return TArray<FVector3f>();
	}
	FSkeletalMeshLODRenderData& LODData = RenderData->LODRenderData[0]; // only LOD0 for simplicity's sake
	FPositionVertexBuffer& VertexBuffer = LODData.StaticVertexBuffers.PositionVertexBuffer;
	FSkinWeightVertexBuffer* SkinWeightBuffer = &LODData.SkinWeightVertexBuffer;
	TArray<FVector3f> Vertices;
	//const TArray<FTransform>& BoneTransforms = SkeletalMeshComponent->GetComponentSpaceTransforms(); // get all bones transforms in current frame
	for (int32 i = 0; i < int32(VertexBuffer.GetNumVertices()); i++)
	{
		FVector3f SkinnedVertexPosition = USkeletalMeshComponent::GetSkinnedVertexPosition(SkeletalMeshComponent,i, LODData, *SkinWeightBuffer);
		Vertices.Add(FVector3f(SkinnedVertexPosition));
		// BELOW ARE SNIPS OF POTENTIALLY USEFUL CODE, OF GETTING BONES TRANSFORMS AND SKIN WEIGHT DATA
		//FSkinWeightInfo SkinWeights = SkinWeightBuffer->GetVertexSkinWeights(i);
		//for (int32 InfluenceIndex = 0; InfluenceIndex < MAX_TOTAL_INFLUENCES; InfluenceIndex++)
		//{
		//	int32 BoneIndex = SkinWeights.InfluenceBones[InfluenceIndex];
		//	float Weight = (float)SkinWeights.InfluenceWeights[InfluenceIndex] / 255.0f; //The division by 255.0f in the code is used to normalize the skin weights. In Unreal Engine, skin weights are typically stored as 8-bit unsigned integers (ranging from 0 to 255) to save memory. To use these weights in calculations, they need to be converted to a floating-point range of 0.0 to 1.0.
		//	//if (Weight == 0.0f || BoneIndex == INDEX_NONE) {	continue;} // skip zero weights and invalid bone indices
		//	if (BoneTransforms.IsValidIndex(BoneIndex))
		//	{
		//		FTransform BoneTransform = BoneTransforms[BoneIndex];
		//		FVector TransformedPosition = BoneTransform.TransformPosition(FVector(VertexBuffer.VertexPosition(i)));
		//		SkinnedVertexPosition += FVector3f(TransformedPosition) * Weight;
		//	}
		//}
	}
	return Vertices;
	
	//return TArray<FVector>();
}
