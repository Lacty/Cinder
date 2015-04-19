## CameraTest

File-> cinder/Camera.h    

CameraPersp型    
***
- setPerspactive(verticalFovDegrees, aspectRatio, nearPlane, farPlane)

- verticalFovDegrees : 視角(60~90がちょうどいいらしい)    
- aspectRatio        : 画面のアスペクト比(getWindowRatio関数で取得可能)    
- Plane              : まだよくわからん
***

- lookAt(eye, center, m_up)

- eye    : 目になるカメラの位置    
- center : eyeを始点にしてどこを向いているのかの中心点    
- up     : よくわからん