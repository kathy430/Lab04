// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownShmup/AIDwarfController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIDwarfController() {}
// Cross Module References
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAIDwarfController_NoRegister();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAIDwarfController();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAIEnemyController();
	UPackage* Z_Construct_UPackage__Script_TopDownShmup();
// End Cross Module References
	void AAIDwarfController::StaticRegisterNativesAAIDwarfController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAIDwarfController);
	UClass* Z_Construct_UClass_AAIDwarfController_NoRegister()
	{
		return AAIDwarfController::StaticClass();
	}
	struct Z_Construct_UClass_AAIDwarfController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRange_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRange;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAIDwarfController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIEnemyController,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownShmup,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDwarfController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AIDwarfController.h" },
		{ "ModuleRelativePath", "AIDwarfController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDwarfController_Statics::NewProp_MaxRange_MetaData[] = {
		{ "Category", "AIDwarfController" },
		{ "Comment", "// max range between a dwarf and a player\n" },
		{ "ModuleRelativePath", "AIDwarfController.h" },
		{ "ToolTip", "max range between a dwarf and a player" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAIDwarfController_Statics::NewProp_MaxRange = { "MaxRange", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAIDwarfController, MaxRange), METADATA_PARAMS(Z_Construct_UClass_AAIDwarfController_Statics::NewProp_MaxRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDwarfController_Statics::NewProp_MaxRange_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAIDwarfController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDwarfController_Statics::NewProp_MaxRange,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAIDwarfController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIDwarfController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAIDwarfController_Statics::ClassParams = {
		&AAIDwarfController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAIDwarfController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAIDwarfController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAIDwarfController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDwarfController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAIDwarfController()
	{
		if (!Z_Registration_Info_UClass_AAIDwarfController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAIDwarfController.OuterSingleton, Z_Construct_UClass_AAIDwarfController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAIDwarfController.OuterSingleton;
	}
	template<> TOPDOWNSHMUP_API UClass* StaticClass<AAIDwarfController>()
	{
		return AAIDwarfController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAIDwarfController);
	struct Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIDwarfController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIDwarfController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAIDwarfController, AAIDwarfController::StaticClass, TEXT("AAIDwarfController"), &Z_Registration_Info_UClass_AAIDwarfController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAIDwarfController), 1490773610U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIDwarfController_h_1610011102(TEXT("/Script/TopDownShmup"),
		Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIDwarfController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIDwarfController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
