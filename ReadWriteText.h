// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HAL/PlatformFilemanager.h"
#include "ReadWriteText.generated.h"

/**
 * 
 */
UCLASS()
class CPPPRACTICE_API UReadWriteText : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//FilePath is input value. bOutSuccess and OutInfoMessage are output value of the function
	UFUNCTION(BlueprintCallable, Category="ReadWriteText")
	static FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category="ReadWriteText")
	static void WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage);
};
