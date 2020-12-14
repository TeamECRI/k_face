# include <Siv3D.hpp> // OpenSiv3D v0.4.2

void Main(){
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.8,0.9,1.0));
	HSV color(0.0,1.0,0.0,1.0);
	// 大きさ 60 のフォントを用意
	const Font font(30);
	double mayu=0,me=0,kuti=0;
	bool checked=false;
	LineString upper{Vec2(370, 380), Vec2(380, 350), Vec2(420, 350),Vec2(430, 380)},lower{Vec2(370, 380), Vec2(380, 350), Vec2(420, 350),Vec2(430, 380)};
	while(System::Update()){
		// テキストを画面の中心に描く
		font(U"顔グラフ").drawAt(Scene::Center().x,15,Palette::Black);
		SimpleGUI::Slider(U"眉",mayu,0.0,10.0,Vec2(Scene::Center().x-375,Scene::Height()-40),60,150);
		SimpleGUI::Slider(U"目",me,0.0,10.0,Vec2(Scene::Center().x-100,Scene::Height()-40),60,150);
		SimpleGUI::Slider(U"口",kuti,0.0,10.0,Vec2(Scene::Center().x+175,Scene::Height()-40),60,150);
		SimpleGUI::CheckBox(checked,U"ゲーミング",Vec2(0,Scene::Height()-240));
		SimpleGUI::VerticalSlider(color.h,0.0,360,Vec2(0,Scene::Height()-200),150,!checked);
		SimpleGUI::VerticalSlider(color.s,0.0,1.0,Vec2(50,Scene::Height()-200),150,!checked);
		SimpleGUI::VerticalSlider(color.v,0.0,1.0,Vec2(100,Scene::Height()-200),150,!checked);
		if(checked){
			color.h+=360.0*Scene::DeltaTime()*0.8;
			if(color.h>360.0)color.h-=360.0;
			color.s=1.0;
			color.v=1.0;
		}

		Circle(Scene::Center(),220).draw(Palette::White);
		Circle(Scene::Center(),200).drawFrame(1,1,color);

		Line(300,240-(4*mayu),370,160+(4*mayu)).draw(2,color);
		Line(430,160+(4*mayu),500,240-(4*mayu)).draw(2,color);

		Circle(335,290,30).stretched(0,-(30-(3*me))).draw(color);
		Circle(335,290,50).stretched(0,-(50-(5*me))).drawFrame(1,1,color);
		Circle(465,290,30).stretched(0,-(30-(3*me))).draw(color);
		Circle(465,290,50).stretched(0,-(50-(5*me))).drawFrame(1,1,color);

		upper[0]=Vec2(370-(4.5*kuti),380);
		upper[1]=Vec2(380,350+(5*kuti));
		upper[2]=Vec2(420,350+(5*kuti));
		upper[3]=Vec2(430+(4.5*kuti),380);
		upper.drawCatmullRom(2,color);

		lower[0]=Vec2(370-(4.5*kuti),380);
		lower[1]=Vec2(380,350+(7*kuti));
		lower[2]=Vec2(420,350+(7*kuti));
		lower[3]=Vec2(430+(4.5*kuti),380);
		lower.drawCatmullRom(2,color);
	}
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
