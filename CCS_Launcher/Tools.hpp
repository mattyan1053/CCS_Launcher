# pragma once
# include <Siv3D.hpp>

/// <summary>
/// 長いテキストをカットして収まらない部分を「...」として省略する。
/// </summary>
/// <param name="str">
/// 変換するテキスト
/// </param>
/// <param name="w">
/// 収めたい横幅
/// </param>
/// <returns></returns>
String MakeTailCutString(String str, int32 w, String fontAsset);