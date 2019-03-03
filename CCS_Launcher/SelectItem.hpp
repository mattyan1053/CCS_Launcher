# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"
# include "Tag.hpp"

/// <summary>
/// アプリケーションアイテム用クラス
/// </summary>
class SelectItem {

private:

	/// <summary>
	/// 全アイテムの先頭位置
	/// </summary>
	static int32 m_itemPos;

	/// <summary>
	/// アイテム数
	/// </summary>
	static int32 m_itemNum;

	/// 	/// <summary>
	/// アイテムのフレーム
	/// </summary>
	RectF m_frame;

	/// <summary>
	/// アイテムアイコンの場所
	/// </summary>
	Vec2 m_pos;

	/// <summary>
	/// アイテムに格納するアプリケーション
	/// </summary>
	AppInfo m_appInfo;

	/// <summary>
	/// マウスが乗せられているかどうかフラグ
	/// </summary>
	bool m_isMouseOver;

	/// <summary>
	/// カーソルをあわせているときの拡大率
	/// </summary>
	double m_stretchRate;

public:


	/// <summary>
	/// アイテムID
	/// </summary>
	const unsigned int id;

	/// <summary>
	/// アイテムのサイズ
	/// </summary>
	static const int32 sizeX = 350;
	const Size itemSize = { sizeX, sizeX * 3 / 4 };
	const double stretchRateMax = 40.0;

	/// <summary>
	/// 余白
	/// </summary>
	static const int32 marginX = 60;
	const int32 marginTop = 150;

	/// <summary>
	/// アプリケーション名タグのサイズ
	/// </summary>
	const Size nameTagSize = { sizeX - 30, 60 };

	/// <summary>
	/// コンストラクタ
	/// アイテムの生成、初期化
	/// </summary>
	/// <param name="pos">
	/// アイテムの初期位置
	/// </param>
	/// <param name="appInfo">
	/// アイテムに格納するアプリケーション情報
	/// </param>
	SelectItem(const unsigned int _id, const AppInfo appInfo);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SelectItem() = default;

	/// <summary>
	/// アイテム情報の更新
	/// </summary>
	/// <returns>
	/// マウスオーバーしていれば true 、していなければ false を返す
	/// </returns>
	bool update(const unsigned int _id);

	/// <summary>
	/// アイテムのクリック判定
	/// </summary>
	/// <returns>
	/// クリックされていれば true 、されていなければ false を返す
	/// </returns>
	bool checkClick();

	/// <summary>
	/// アイテムの描画
	/// </summary>
	void draw() const;

	/// <summary>
	/// アイテムの横幅の取得
	/// </summary>
	/// <returns>
	/// 余白込みアイテム全体の横幅
	/// </returns>
	int getItemWidth() {
		return itemSize.x + marginX;
	}

	/// <summary>
	/// アイテム全体開始位置の移動
	/// </summary>
	/// <param name="diff">
	/// 移動距離
	/// </param>
	static void moveItemPos(int32 diff);

	/// <summary>
	/// アイテム数の設定
	/// </summary>
	/// <param name="itemNum">
	/// アイテム数
	/// </param>
	static void setItemNum(int32 itemNum);

	/// <summary>
	/// アイテム位置状態用列挙体
	/// </summary>
	enum posState {

		/// <summary>
		/// 通常の状態
		/// </summary>
		ok,

		/// <summary>
		/// 左側にはみでている
		/// </summary>
		overLeft,

		/// <summary>
		/// 右側にはみでている
		/// </summary>
		overRight
	};

	/// <summary>
	/// アイテム位置修正(画面外判定)
	/// </summary>
	/// <returns>
	/// はみ出ていなければ ok 、左側にはみ出たとき overLeft 、右側にはみでたとき overRight を返す
	/// </returns>
	static posState checkPos();

};