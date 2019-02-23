# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Defines.hpp"
# include "Fade.hpp"

/// <summary>
/// シーン遷移で共有するデータ
/// </summary>
struct ShereData {

	/// <summary>
	/// 選択中のアプリケーションID
	/// </summary>
	unsigned int selectedID;

	/// <summary>
	/// アプリケーション情報の配列
	/// </summary>
	Array<AppInfo> apps;

	/// <summary>
	/// プロセスの実行フラグ
	/// </summary>
	Optional<ProcessInfo> process;
};

using SceneChanger = SceneManager<String, ShereData>;

/// <summary>
/// シーン遷移クラス用基底クラス
/// </summary>
/// <remarks>
/// 純粋仮想関数を含むので、インスタンス化不可
/// </remarks>
class BaseScene : public SceneChanger::Scene{

public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	BaseScene() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BaseScene() = default;

	/// <summary>
	/// 情報更新&シーン遷移
	/// </summary>
	void update() override;

	/// <summary>
	/// ランチャーの更新
	/// </summary>
	/// <remarks>
	/// プロセスの起動判定をしたあと呼ばれる。
	/// 必ずオーバーライドすること
	/// </remarks>
	virtual void updateLauncher() = 0;

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