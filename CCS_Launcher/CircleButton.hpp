# pragma once
# include "Button.hpp"

/// <summary>
/// 丸いボタンクラス
/// </summary>
class CircleButton : public Button {

private:

	/// <summary>
	/// ボタン用円
	/// </summary>
	Circle m_button;

public:

	/// <summary>
	/// 円の半径
	/// </summary>
	int32 r;

	/// <summary>
	/// ボタン設定
	/// </summary>
	/// <param name="_pos">
	/// ボタンの中心座標
	/// </param>
	/// <param name="_r">
	/// ボタン半径
	/// </param>
	/// <param name="_text">
	/// ボタンのテキスト
	/// </param>
	void set(Point _pos, int32 _r, String _text);

	/// <summary>
	/// ボタンのクリック判定
	/// </summary>
	/// <returns>
	/// 押されていれば true 、押されていなければ false を返す
	/// </returns>
	bool update();

	/// <summary>
	/// ボタン描画
	/// </summary>
	void draw() const;

};
