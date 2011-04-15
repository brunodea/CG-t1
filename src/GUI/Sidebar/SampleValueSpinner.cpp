#include "../../../include/GUI/Sidebar/SampleValueSpinner.h"

#include <SCV/Point.h>

using namespace GUI;

SampleValueSpinner::SampleValueSpinner(int pos_x, int pos_y)
   : scv::Spinner(scv::Point(pos_x, pos_y), SAMPLE_SPINNER_WIDTH, SAMPLE_SPINNER_MIN_VALUE, SAMPLE_SPINNER_MAX_VALUE, 0, 1)
{
}
