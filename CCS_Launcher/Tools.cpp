# pragma once
# include "Tools.hpp"

String MakeTailCutString(String str, int32 w, String fontAsset) {

	String retStr = str;

	const size_t n = Max<size_t>(FontAsset(fontAsset).drawableCharacters(retStr, w), 1);
	const bool overflow = (n < str.length);

	if (overflow) {
		retStr = retStr.substr(0, n - 2);
		retStr += L"...";
	}

	return retStr;

}