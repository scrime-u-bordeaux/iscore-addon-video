#pragma once
#include <VideoProcess/Commands/VideoCommandFactory.hpp>
#include <iscore/command/SerializableCommand.hpp>
#include <iscore/tools/ModelPath.hpp>

#include <VideoProcess/ScaleMode.hpp>


struct DataStreamInput;
struct DataStreamOutput;
namespace Video
{
class ProcessModel;

class SetVideo final : public iscore::SerializableCommand
{
        ISCORE_COMMAND_DECL(Video::CommandFactoryName(), SetVideo, "Set a video")
    public:
        SetVideo(
                Path<ProcessModel>&& model,
                const QString& path);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
        QString m_old, m_new;
};

}
