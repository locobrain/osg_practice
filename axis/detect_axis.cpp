#include <iostream>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osg/Shape>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/GraphicsContext>

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
#if 0	// 这两种方案在本例中是没有差别的 [11/26/2018 brian.wang]
	v.setSceneData(root);
#else
	v.getCamera()->addChild(root);
#endif
	// 如下代码没有效果 [11/26/2018 brian.wang]
	//	v.getCamera()->getGraphicsContext()->setClearColor(osg::Vec4());

	/*	如下代码竟然也没有效果
	auto gc = osg::GraphicsContext::createGraphicsContext(new osg::GraphicsContext::Traits(*v.getCamera()->getGraphicsContext()->getTraits()));
	gc->setClearColor(osg::Vec4());
	v.getCamera()->setGraphicsContext(gc);
	*/

	/*	如下代码竟然也没有效果
	auto camera_ =  v.getCamera();
	auto _camera = new osg::Camera(*camera_);
	auto gc = osg::GraphicsContext::createGraphicsContext(new osg::GraphicsContext::Traits(*v.getCamera()->getGraphicsContext()->getTraits()));
	gc->setClearColor(osg::Vec4());
	gc->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_camera->setGraphicsContext(gc);
	osg::StateSet* stateset = _camera->getOrCreateStateSet();
	stateset->setGlobalDefaults();
	v.setCamera(_camera);
	*/

	v.getCamera()->setClearColor(osg::Vec4());
	

#if 0	// 貌似没什么用删除 [11/26/2018 brian.wang]
	v.addEventHandler(new osgViewer::StatsHandler());
#endif
	
	
	v.run();
	return 0;
}