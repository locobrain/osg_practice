# 描述
主要为了验证OSG默认坐标系。其中红是X轴、绿色是Y轴、蓝色是Z轴。

# TRIPS
1. osgViewer::Viewer会在run的时候创建一个osgGA::TrackballManipulator；
2. 关闭光照后材质效果是不生效的；
3. 基本图形的状态需要配置基本的图形的Drawable，普通Drawable是不可以正确显示图形的；
4. 挂接要显示的数据通过osgViewer::Viewer的setSceneData函数
5. Camera(const Camera&,const CopyOp& copyop=CopyOp::SHALLOW_COPY)并没有拷贝GraphicsContext对象
5. setClearColor、GraphicsContext和Camera都有这个成员只有Camera的这个是正确的。