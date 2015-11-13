/**************************************************************************
 *
 * Copyright 2015 Intel Corporation
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 **************************************************************************/

#ifndef _GLFRAME_RETRACE_RENDER_HPP_
#define _GLFRAME_RETRACE_RENDER_HPP_

#include <vector>

#include "trace_loader.hpp"

namespace trace {
class Parser;
}

namespace retrace {
class Retracer;
}

namespace glretrace {

class StateTrack;
class OnFrameRetrace;
class ExperimentId;
class MetricId;

class RetraceRender {
 public:
  RetraceRender(trace::Parser *parser,
                retrace::Retracer *retracer,
                StateTrack *tracker);
  void retraceRenderTarget() const;
  void retrace(StateTrack *tracker = NULL) const;
  bool endsFrame() const { return m_end_of_frame; }
  void overrideProgram(int program);
  void overrideRenderTargetProgram(int program);

 private:
  trace::Parser *m_parser;
  retrace::Retracer *m_retracer;
  trace::RenderBookmark m_bookmark;
  int m_program;
  int m_rt_program;
  int m_override_program;
  bool m_end_of_frame;
};

}  // namespace glretrace

#endif  // _GLFRAME_RETRACE_RENDER_HPP_