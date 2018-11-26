#include <iostream>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osg/Shape>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Material>

int main(_In_ int _Argc, _In_reads_(_Argc) _Pre_z_ char ** _Argv, _In_z_ char ** _Env)
{
	osgViewer::Viewer v;
	v.setUpViewInWindow(100, 100, 1027, 768);

	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<osg::Geode> xObj = new osg::Geode();
	xObj->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.5f, 0.000f, 0.000f), 1.0f, 0.01f, 0.01f)));
	auto xMat = new osg::Material();
	xMat->setAmbient(osg::Material::FRONT, osg::Vec4(1.0f, 0.0f, 0.0f, 0.0f));
	xMat->setDiffuse(osg::Material::FRONT, osg::Vec4(1.0f, 0.0f, 0.0f, 0.0f));
	xObj->getOrCreateStateSet()->setAttribute(xMat);
	root->addChild(xObj);

	osg::ref_ptr<osg::Geode> yObj = new osg::Geode();
	yObj->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.005f, 0.5f, 0.005f), 0.01f, 1.00f, 0.01f)));
	auto yMat = new osg::Material();
	yMat->setColorMode(osg::Material::OFF);
	yMat->setAmbient(osg::Material::FRONT, osg::Vec4(0.0f, 1.0f, 0.0f, 0.0f));
	yMat->setDiffuse(osg::Material::FRONT, osg::Vec4(0.0f, 1.0f, 0.0f, 0.0f));
	yObj->getOrCreateStateSet()->setAttribute(yMat);
#if 0	// 禁止光照后颜色材质是不生效的 [11/26/2018 brian.wang]
	yObj->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
#endif
	root->addChild(yObj);

	osg::ref_ptr<osg::Geode> zObj = new osg::Geode();
	zObj->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.005f, 0.005f, 0.5f), 0.01f, 0.01f, 1.0f)));
	auto zMat = new osg::Material();
	zMat->setAmbient(osg::Material::FRONT, osg::Vec4(0.0f, 0.0f, 1.0f, 0.0f));
	zMat->setDiffuse(osg::Material::FRONT, osg::Vec4(0.0f, 0.0f, 1.0f, 0.0f));
	zObj->getOrCreateStateSet()->setAttribute(zMat);
	root->addChild(zObj);
	v.setSceneData(root);

#if 0	// 貌似没什么用删除 [11/26/2018 brian.wang]
	v.addEventHandler(new osgViewer::StatsHandler());
#endif
	
	v.run();
	return 0;
}