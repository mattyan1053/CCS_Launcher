# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"

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
	static const int32 sizeX = 300;
	const Size itemSize = { sizeX, sizeX * 3 / 4 };
	static const int32 marginX = 60;
	const int32 marginTop = 130;
	const double stretchRateMax = 40.0;

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
	/// マウスオーバーしていれば 1 、していなければ 0 を返す
	/// </returns>
	int update(const unsigned int _id);

	/// <summary>
	/// アイテムのクリック判定
	/// </summary>
	/// <returns>
	/// クリックされていれば 1 、されていなければ 0 を返す
	/// </returns>
	int checkClick();

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

};