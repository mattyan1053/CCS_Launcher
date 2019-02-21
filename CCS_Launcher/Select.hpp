# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

/// <summary>
/// アプリケーション選択画面
/// </summary>
class Select : public SceneChanger::Scene {

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Select();

	/// <summary>
	/// 画面情報更新&シーン遷移
	/// </summary>
	void update() override;

	/// <summary>
	/// 画面描画
	/// </summary>
	void draw() const override;

};