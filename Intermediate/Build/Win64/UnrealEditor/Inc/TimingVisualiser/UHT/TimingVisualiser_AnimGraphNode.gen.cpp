// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimingVisualiser/Public/TimingVisualiser_AnimGraphNode.h"
#include "TimingVisualiser/Public/TimingVisualiser_AnimNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTimingVisualiser_AnimGraphNode() {}

// Begin Cross Module References
ANIMGRAPH_API UClass* Z_Construct_UClass_UAnimGraphNode_Base();
TIMINGVISUALISER_API UClass* Z_Construct_UClass_UTimingVisualiser_AnimGraphNode();
TIMINGVISUALISER_API UClass* Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_NoRegister();
TIMINGVISUALISER_API UScriptStruct* Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode();
UPackage* Z_Construct_UPackage__Script_TimingVisualiser();
// End Cross Module References

// Begin Class UTimingVisualiser_AnimGraphNode
void UTimingVisualiser_AnimGraphNode::StaticRegisterNativesUTimingVisualiser_AnimGraphNode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTimingVisualiser_AnimGraphNode);
UClass* Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_NoRegister()
{
	return UTimingVisualiser_AnimGraphNode::StaticClass();
}
struct Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "TimingVisualiser_AnimGraphNode.h" },
		{ "ModuleRelativePath", "Public/TimingVisualiser_AnimGraphNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimingVisualiserNode_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/TimingVisualiser_AnimGraphNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TimingVisualiserNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTimingVisualiser_AnimGraphNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::NewProp_TimingVisualiserNode = { "TimingVisualiserNode", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTimingVisualiser_AnimGraphNode, TimingVisualiserNode), Z_Construct_UScriptStruct_FTimingVisualiser_AnimNode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimingVisualiserNode_MetaData), NewProp_TimingVisualiserNode_MetaData) }; // 1712990356
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::NewProp_TimingVisualiserNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_Base,
	(UObject* (*)())Z_Construct_UPackage__Script_TimingVisualiser,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::ClassParams = {
	&UTimingVisualiser_AnimGraphNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTimingVisualiser_AnimGraphNode()
{
	if (!Z_Registration_Info_UClass_UTimingVisualiser_AnimGraphNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTimingVisualiser_AnimGraphNode.OuterSingleton, Z_Construct_UClass_UTimingVisualiser_AnimGraphNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTimingVisualiser_AnimGraphNode.OuterSingleton;
}
template<> TIMINGVISUALISER_API UClass* StaticClass<UTimingVisualiser_AnimGraphNode>()
{
	return UTimingVisualiser_AnimGraphNode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTimingVisualiser_AnimGraphNode);
UTimingVisualiser_AnimGraphNode::~UTimingVisualiser_AnimGraphNode() {}
// End Class UTimingVisualiser_AnimGraphNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimGraphNode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTimingVisualiser_AnimGraphNode, UTimingVisualiser_AnimGraphNode::StaticClass, TEXT("UTimingVisualiser_AnimGraphNode"), &Z_Registration_Info_UClass_UTimingVisualiser_AnimGraphNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTimingVisualiser_AnimGraphNode), 1239291398U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimGraphNode_h_3638085773(TEXT("/Script/TimingVisualiser"),
	Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimGraphNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Projects_TimingVisualiser_Source_TimingVisualiser_Public_TimingVisualiser_AnimGraphNode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
