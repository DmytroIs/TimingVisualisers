// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimingVisualiser/Public/TimingVisualiser_AnimNode.h"
#include "Runtime/Engine/Classes/Animation/AnimNodeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTimingVisualiser_AnimNode() {}

// Begin Cross Module References
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_Base();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentSpacePoseLink();
TIMINGVISUALISER_API UScriptStruct* Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode();
UPackage* Z_Construct_UPackage__Script_TimingVisualiser();
// End Cross Module References

// Begin ScriptStruct FTimingVisualiser_AnimNode
static_assert(std::is_polymorphic<FTimingVisualiser_AnimNode>() == std::is_polymorphic<FAnimNode_Base>(), "USTRUCT FTimingVisualiser_AnimNode cannot be polymorphic unless super FAnimNode_Base is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode;
class UScriptStruct* FTimingVisualiser_AnimNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode, (UObject*)Z_Construct_UPackage__Script_TimingVisualiser(), TEXT("TimingVisualiser_AnimNode"));
	}
	return Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode.OuterSingleton;
}
template<> TIMINGVISUALISER_API UScriptStruct* StaticStruct<FTimingVisualiser_AnimNode>()
{
	return FTimingVisualiser_AnimNode::StaticStruct();
}
struct Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/TimingVisualiser_AnimNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BasePose_MetaData[] = {
		{ "Category", "Links" },
		{ "ModuleRelativePath", "Public/TimingVisualiser_AnimNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinVelocity_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//FPoseLink\n//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))\n//FName TestBoneName;\n" },
#endif
		{ "ModuleRelativePath", "Public/TimingVisualiser_AnimNode.h" },
		{ "PinShownByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FPoseLink\nUPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))\nFName TestBoneName;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowMagnitude_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/TimingVisualiser_AnimNode.h" },
		{ "PinShownByDefault", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_BasePose;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArrowMagnitude;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTimingVisualiser_AnimNode>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewProp_BasePose = { "BasePose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTimingVisualiser_AnimNode, BasePose), Z_Construct_UScriptStruct_FComponentSpacePoseLink, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BasePose_MetaData), NewProp_BasePose_MetaData) }; // 1693320103
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewProp_MinVelocity = { "MinVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTimingVisualiser_AnimNode, MinVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinVelocity_MetaData), NewProp_MinVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewProp_ArrowMagnitude = { "ArrowMagnitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTimingVisualiser_AnimNode, ArrowMagnitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowMagnitude_MetaData), NewProp_ArrowMagnitude_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewProp_BasePose,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewProp_MinVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewProp_ArrowMagnitude,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_TimingVisualiser,
	Z_Construct_UScriptStruct_FAnimNode_Base,
	&NewStructOps,
	"TimingVisualiser_AnimNode",
	Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::PropPointers),
	sizeof(FTimingVisualiser_AnimNode),
	alignof(FTimingVisualiser_AnimNode),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode()
{
	if (!Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode.InnerSingleton, Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode.InnerSingleton;
}
// End ScriptStruct FTimingVisualiser_AnimNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimNode_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FTimingVisualiser_AnimNode::StaticStruct, Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode_Statics::NewStructOps, TEXT("TimingVisualiser_AnimNode"), &Z_Registration_Info_UScriptStruct_TimingVisualiser_AnimNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTimingVisualiser_AnimNode), 1712990356U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimNode_h_2661338039(TEXT("/Script/TimingVisualiser"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimNode_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimNode_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
