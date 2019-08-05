#ifndef THERMAL_CAM_H
#define THERMAL_CAM_H

#ifdef _PRINT_HEADER_
  #warning "thermal_cam.h"
#endif
#include "gui_helper_functions.h"
#include "GraphicsCamera.h"
#inclde "GraphicsWindowInterface.h"
namespace mars {
  namespace graphics {

      class thermal_cam {

        public:
       
      virtual void getTempImageData(char *buffer, int &width, int &height);
      //virtual void getTempImageData(void **data, int &width, int &height);

      } // end of namespace interfaces
} // end of namespace mars

#endif  /* MARS_GRAPHICS_THERMAL_CAM_H */
