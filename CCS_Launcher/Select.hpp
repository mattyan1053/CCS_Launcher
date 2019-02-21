# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

/// <summary>
/// アプリケーション選択画面
/// </summary>
class Select : public BaseScene {

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Select();

	void updateLauncher() override;

	/// <summary>
	/// 画面描画
	/// </summary>
	void draw() const override;

};