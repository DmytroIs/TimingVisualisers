// Fill out your copyright notice in the Description page of Project Settings.


#include "TimingVisualiser_AnimGraphNode.h"

UTimingVisualiser_AnimGraphNode::UTimingVisualiser_AnimGraphNode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FString UTimingVisualiser_AnimGraphNode::GetNodeCategory() const
{
	return FString("AAA Dmytro Weird Tests");
}

FLinearColor UTimingVisualiser_AnimGraphNode::GetNodeTitleColor() const
{
	return FLinearColor (0.75f, 0.75f, 0.75f);
}
FText UTimingVisualiser_AnimGraphNode::GetTooltipText() const
{
	return FText::FromString(
		"CachedFramesNumber - how many frames to average velocity and acceleration\n"
		"Min Velocity and Min Acceleration - the significance cutoff of the debug data\n"
		"DirectionThreshold - a value between -1 and 1, from opposite to same direction,"
		" with 0 for perpendicular (normalized dot product of velocity and acceleration)\n"
		"Bone Names Filter Out (in the node settings) - remove the bone by part of the name from debug draw");
}

FText UTimingVisualiser_AnimGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString("Velocities Visualiser");
}

void UTimingVisualiser_AnimGraphNode::CreateOutputPins()
{
	CreatePin(EGPD_Output, UAnimationGraphSchema::PC_Struct, FComponentSpacePoseLink::StaticStruct(), TEXT("Component Space Pose"));
}