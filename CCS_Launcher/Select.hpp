# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "SelectItem.hpp"
# include "Button.hpp"

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

	int32 m_itemPos;

public:

	/// <summary>
	/// 概要欄パラメータ
	/// </summary>
	const Point summaryPos = {20, 450};
	const Size summarySize = { 700, 250 };

	/// <summary>
	/// ボタンパラメータ
	/// </summary>
	const Size buttonSize = { 200, 60 };
	const Point buttonPos = { summaryPos + summarySize - buttonSize - Point(50, 20) };

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