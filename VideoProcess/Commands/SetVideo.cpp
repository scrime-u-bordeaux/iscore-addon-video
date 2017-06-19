#include <VideoProcess/VideoModel.hpp>

#include "SetVideo.hpp"
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/model/path/PathSerialization.hpp>
namespace Video
{
SetVideo::SetVideo(
    const ProcessModel& obj,
    const QString& text):
  m_model{obj},
  m_new{text}
{
    m_old = obj.file().path;
}

void SetVideo::undo(const iscore::DocumentContext& ctx) const
{
    m_model.find(ctx).setFile(VideoFile{m_old});
}

void SetVideo::redo(const iscore::DocumentContext& ctx) const
{
    m_model.find(ctx).setFile(VideoFile{m_new});

}

void SetVideo::serializeImpl(DataStreamInput& s) const
{
    s << m_model << m_old << m_new;
}

void SetVideo::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model >> m_old >> m_new;
}

}
