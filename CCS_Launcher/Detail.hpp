# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

/// <summary>
/// アプリケーション内容詳細＆起動画面
/// </summary>
class Detail : public BaseScene {

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Detail();

	/// <summary>
	/// 画面情報更新&シーン遷移
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// 画面描画
	/// </summary>
	void draw() const override;

};