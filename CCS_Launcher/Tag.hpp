# pragma once
# include <Siv3D.hpp>

/// <summary>
/// 付箋クラス
/// </summary>
class Tag {

private:

	/// <summary>
	/// 付箋に表示するテキスト
	/// </summary>
	String text;

	/// <summary>
	/// 付箋用矩形
	/// </summary>
	Rect rect;

	/// <summary>
	/// 背景色
	/// </summary>
	Color clr;

	/// <summary>
	/// ２D回転用
	/// </summary>
	Mat3x2 mat;

public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Tag() = default;

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">
	/// 付箋の位置
	/// </param>
	/// <param name="size">
	/// 付箋のサイズ
	/// </param>
	/// <param name="_text">
	/// 付箋のテキスト
	/// </param>
	Tag(Point pos, Size size, String _text);

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">
	/// 付箋の位置
	/// </param>
	/// <param name="size">
	/// 付箋のサイズ
	/// </param>
	/// <param name="_text">
	/// 付箋のテキスト
	/// </param>
	/// <param name="_clr">
	/// 付箋色
	/// </param>
	Tag(Point pos, Size size, String _text, Color _clr);

	/// <summary>
	/// パラメータ再設定
	/// </summary>
	/// <param name="pos">
	/// 付箋位置
	/// </param>
	/// <param name="size">
	/// 付箋のサイズ
	/// </param>
	/// <param name="_text">
	/// 付箋のテキスト
	/// </param>
	void set(Point pos, Size size, String _text);

	/// <summary>
	/// 背景色付き設定
	/// </summary>
	/// <param name="pos">
	/// 付箋位置
	/// </param>
	/// <param name="size">
	/// 付箋サイズ
	/// </param>
	/// <param name="_text">
	/// 付箋テキスト
	/// </param>
	/// <param name="_clr">
	/// 付箋色
	/// </param>
	void set(Point pos, Size size, String _text, Color _clr);

	Point center() const {
		return rect.center;
	}

	/// <summary>
	/// 付箋の描画
	/// </summary>
	void draw() const;

};