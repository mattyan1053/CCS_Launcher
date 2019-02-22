# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "Button.hpp"
# include "Tag.hpp"
# include "InlineFrame.hpp"
# include "Fade.hpp"

/// <summary>
/// アプリケーション内容詳細＆起動画面
/// </summary>
class Detail : public BaseScene {

private:

	/// <summary>
	/// ゲームの開始ボタン
	/// </summary>
	Button m_startButton;

	/// <summary>
	/// セレクト画面へ戻るボタン
	/// </summary>
	Button m_backButton;

	/// <summary>
	/// ゲームジャンル
	/// </summary>
	Tag m_kind;

	/// <summary>
	/// 操作方法
	/// </summary>
	Tag m_usetext;

	/// <summary>
	/// Readme フレーム
	/// </summary>
	InlineFrame frame;

public:

	/// <summary>
	/// 上下左右の空白
	/// </summary>
	const int32 marginLeft = 30;
	const int32 marginRight = 50;
	const int32 marginTop = 60;
	const int32 marginBottom = 50;

	/// <summary> 
	/// ボタンサイズ
	/// </summary>
	const int32 buttonSizeX = 230;
	const int32 buttonSizeY = 60;
	const Size buttonSize = { buttonSizeX, buttonSizeY };
	const Point startButtonPos = {marginLeft, Window::Size().y - marginBottom - buttonSizeY};
	const Point backButtonPos = { marginLeft + buttonSizeX + 30, Window::Size().y - marginBottom - buttonSizeY };

	/// <summary>
	/// スクリーンショットサイズ
	/// </summary>
	const Point screenshotPos = { marginLeft, marginTop + 80 };
	const int32 screenshotSizeX = 450;
	const Size screenshotSize = { screenshotSizeX, screenshotSizeX * 3 / 4 };

	/// <summary>
	/// タグサイズ
	/// </summary>
	const Point tagPos = { marginLeft, marginTop + 80 + screenshotSize.y };
	const Size tagSize = { 500, 50 };

	/// <summary>
	/// Readme サイズ
	/// </summary>
	const Point readmePos = { marginLeft + screenshotSizeX + 100, 80 };
	const Size readmeSize = Window::Size() - readmePos - Size(marginLeft, 30);

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Detail() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void init() override;

	/// <summary>
	/// 画面情報更新&シーン遷移
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// 画面描画
	/// </summary>
	void draw() const override;

	/// <summary>
	/// フェードイン時の演出
	/// </summary>
	void drawFadeIn(double t) const override {
		draw();
		FadeIn(t);
	}

	/// <summary>
	/// フェードアウト時の演出
	/// </summary>
	void drawFadeOut(double t) const override {
		draw();
		FadeOut(t);
	}

};