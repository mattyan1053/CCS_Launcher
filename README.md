# CCS_Launcher

## このランチャーについて

### 制作の経緯
このランチャーは、千葉大学電子計算機研究会（通称CCS）のゲーム展示のためのランチャーとして制作しました。  

### 使い方
Gameフォルダ内にアプリケーション全体を含むフォルダを配置します。  
このとき、フォルダの名前がゲームの名前としてランチャーでは表示されます。  

ゲーム内には最低限次の３つのファイルが存在する必要があります。  
・実行ファイル（.exeなど）  
・readme.txt（操作説明など）  
・screenshot.png（pngでなくてもいいですが、拡張子抜きの名前がscreenshotになるようにお願いします。）  
・info.txt（後述）  

また、なくてもいいですが、「demo.avi」または「demo.wmv」があるとこれも読み込んで再生することができます。

info.txtには次の内容を記述してください。全部で３行です。  
・実行ファイル名  
・ゲームジャンル  
・ゲーム操作に使うもの  
ex.  
mygame.exe  
シューティング  
キーボード  

#### 実行ファイルで対応しているもの
EXEファイルは起動できます。HTMLやjarファイルなど、他のアプリケーション下で動くものは実行できません。batファイルは実行できるので、起動コマンドをbatファイルに記述して、info.txtの実行ファイル名のところにbatファイルの名前を書いてください。

### 操作方法
画面左右のボタンをクリックすることでスクロールしたりします。また、マウスホイールでのスクロールも対応しています。  

選択画面ではスクリーンショットをクリックするか、「くわしく見る」ボタンで詳細画面に遷移してreadmeを読むことができるようになっており、ここから起動もできます。

デモムービーは右上のDemoボタンのほか、２分間操作がなかったときにも自動で再生するようになっています。元の画面に戻るときはマウスの左クリックかキーをなにか押してください。

## 制作

### 制作者
抹茶(Twitter@mattyan1053)  

### 使用したライブラリ等
Siv3D(August2016v2)(https://play-siv3d.hateblo.jp/)  
