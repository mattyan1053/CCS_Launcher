# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "SelectItem.hpp"
# include "Button.hpp"
# include "CircleButton.hpp"

/// <summary>
/// アプリケーション選択画面
/// </summary>
class Select : public BaseScene {

private:

	/// <summary>
	/// アイテム配列
	/// </summary>
	Array<SelectItem> m_items;

	/// <summary>
	/// 概要欄用矩形
	/// </summary>
	Rect m_frameSummary;

	/// <summary>
	/// 詳細ボタン
	/// </summary>
	Button m_detailButton;

	/// <summary>
	/// デモ遷移ボタン
	/// </summary>
	Button m_demoButton;

	/// <summary>
	/// アイテム位置移動ボタン左
	/// </summary>
	CircleButton m_leftButton;

	/// <summary>
	/// アイテム位置移動ボタン右
	/// </summary>
	CircleButton m_rightButton;

	/// <summary>
	/// アイテム移動フラグ
	/// </summary>
	int32 m_moveFlag = 0;

public:

	/// <summary>
	/// 概要欄パラメータ
	/// </summary>
	const Point summaryPos = { 120, 450 };
	const Size summarySize = { 700, 250 };

	/// <summary>
	/// ボタンパラメータ
	/// </summary>
	const Size buttonSize = { 200, 60 };
	const Point buttonPos = { summaryPos + summarySize - buttonSize - Point(50, 20) };
	const Point demoButtonPos = { Window::Size().x - buttonSize.x - 50, 10 };
	const int32 moveButtonRadius = 40;
	const Point leftButtonPos = { 20 + moveButtonRadius, 240 };
	const Point rightButtonPos = { Window::Size().x - 20 - moveButtonRadius, 240 };

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Select() = default;

	/// <summary>
	/// シーンクラスの初期化
	/// </summary>
	void init() override;

	/// <summary>
	/// 動作中の画面更新(シーン遷移中及び他のシーン中は呼ばれない)
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// 画面描画
	/// </summary>
	void draw() const override;

};