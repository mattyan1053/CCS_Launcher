# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Defines.hpp"

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
/// ゲーム起動中かどうかでウィンドウの状態を変更する。
/// </summary>
/// <param name="process">
/// process != noneのときゲームが起動中としてランチャーを最小化
/// process == none のときゲームが終了していると判断して最小化を解除する
/// </param>
/// <returns>
/// プロセスが起動していれば false、起動していなければ true を返す
/// </returns>
bool CheckWindowState(Optional<ProcessInfo> process);

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
	/// 画面情報更新&シーン遷移
	/// </summary>
	void update() override;

	virtual void updateLauncher() = 0;

};