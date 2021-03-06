#pragma once

#include "SlateBasics.h"
#include "AssetRegistryModule.h"

namespace libgltf
{
    struct SGlTF;
}

class SglTFImportWindow : public SCompoundWidget
{
public:
    static TSharedPtr<struct FglTFImportOptions> Open(const FString& InFilePathInOS, const FString& InFilePathInEngine, const libgltf::SGlTF& InGlTF, bool& OutCancel);

public:
    SLATE_BEGIN_ARGS(SglTFImportWindow)
        : _GlTF(nullptr)
        , _glTFImportOptions(nullptr)
        , _WidgetWindow(nullptr)
        {}

        SLATE_ARGUMENT(TSharedPtr<libgltf::SGlTF>, GlTF)
        SLATE_ARGUMENT(TSharedPtr<struct FglTFImportOptions>, glTFImportOptions)
        SLATE_ARGUMENT(TSharedPtr<SWindow>, WidgetWindow)
    SLATE_END_ARGS()

public:
    SglTFImportWindow();

public:
    void Construct(const FArguments& InArgs);

public:
    virtual bool SupportsKeyboardFocus() const override;
    virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

public:
    TSharedPtr<struct FglTFImportOptions> GetImportOptions();

protected:
    bool CanImport() const;
    FReply OnImport();
    FReply OnCancel();
    void HandleImportAllScenes(ECheckBoxState InCheckBoxState);
    void HandleImportSkeleton(ECheckBoxState InCheckBoxState);
    void HandleImportMaterial(ECheckBoxState InCheckBoxState);
    void HandleMeshScaleRatioX(float InNewValue);
    void HandleMeshScaleRatioY(float InNewValue);
    void HandleMeshScaleRatioZ(float InNewValue);
    void HandleMeshInvertNormal(ECheckBoxState InCheckBoxState);
    void HandleMeshUseMikkTSpace(ECheckBoxState InCheckBoxState);
    void HandleMeshRecomputeNormals(ECheckBoxState InCheckBoxState);
    void HandleMeshRecomputeTangents(ECheckBoxState InCheckBoxState);

private:
    TWeakPtr<libgltf::SGlTF> GlTF;
    TWeakPtr<struct FglTFImportOptions> glTFImportOptions;
    TWeakPtr<SWindow> WidgetWindow;
};
