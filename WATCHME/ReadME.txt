ゲーム概要
ステージを歩き回って敵を倒すゲーム。
ひろったアイテムで自分を強化できる（未実装）

操作方法
WASD(前/左/後/右)
Space(攻撃/決定)
Enter(武器を初期位置に戻す/武器の当たり判定を消す　現在武器を振り下ろすとEnemyに当たらないと元の位置に戻らないため）

力を入れた個所
Enemy.cpp　void PlayerChase();
Enemyが一定距離に近づいたPlayerを追ってくるようにしました
(Enemyを複数体出しても、特定の一体しか追ってこないので直したい）




今のところ実装できてる箇所
・剣で敵を倒す
・アイテムを取得する(赤いわっか）
・HPが0になるとResult(仮）にとぶ

今後の課題
剣を振り下ろす、元の位置に戻る動きを一つのキーを押しただけでやりたい
当たり判定の位置がいまいちわからない
ミッション表示、管理
Enemyを倒した数をリザルトシーンに表示
グラフィックを向上する



GitHub URL
https://github.com/misyaya/GetChocolate/tree/Sword_new

フォルダ構成
D:.
ProjectFile
├.git
├.vs
├Assets
│    ├DebugCollision
│    │            ├BoxCollider.fbx
│    │            └SphereCollider.fbx
│    ├Shader
│    │     ├BillBoard.hlsl
│    │     ├Debug3D.hlsl
│    │     ├Simple2D.hlsl
│    │     └Simple3D.hlsl
│    ├Box.fbx
│    ├brick.jpg
│    ├char.png
│    ├defaultPrticle.png
│    ├Enemy.fbx
│    ├Floor.fbx
│    ├Hp.png
│    ├HpFive.png
│    ├LifeGauge.png
│    ├LifeGauge_Frame.png
│    ├Sample.fbx
│    ├Sample2.fbx
│    ├setup.ini
│    ├Sword.fbx
│    └Tex.png
│
├Engine //変更点のみ記載
│     └Imgui
│
├x64
│
├gitattributes
├gitignore
├Back_Title.cpp
├Back_Title.h
├Chocolate.cpp
├Chocolate.h
├Enemy.cpp
├Enemy.h
├EnemyManager.cpp
├EnemyManager.h
├Floor.cpp
├Floor.h
├GameBaseDx11.vcxproj
├GameBaseDx11.vcxproj.filters
├GameBaseDx11.vcxproj.user
├GetChocolate.sln
├LifeGauge.cpp
├LifeGauge.h
├MainGameScene.cpp
├MainGameScene.h
├Mission.cpp
├Mission.h
├MissionDisplay.cpp
├MissionDisplay.h
├MissionManager.cpp
├MissionManager.h
├Player.cpp
├Player.h
├ResultScene.cpp
├ResultScene.h
├StartButton.cpp
├StartButton.h
├Sword.cpp
├Sword.h
├TitleLogo.cpp
├TitleLogo.h
├TitleScene.cpp
└TitleScene.h

