// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWriteText.h"

FString UReadWriteText::ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
	//check if the file exist
	if(!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		//If the target file does not exist, end the script
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("The target file does not exist"));
		return "";
		
	}

	//The function need to store the string
	FString TargetString;
	
	//Check if string exist, load the file to string
	if (!FFileHelper::LoadFileToString(TargetString, *FilePath))
	{
		//If there is no string in the file, end the script
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("The target string does not exist"));
		return "";
	}

	//If all succeed, return the value and info
	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read file succeed"));
	return  TargetString;
	
}

void UReadWriteText::WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)
{
	if(!FFileHelper::SaveStringToFile(String, *FilePath))
	{
		//If we didn't input string
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Please input sting"));
		return;
	}

	//If string input succeed
	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write string to file"));
}

