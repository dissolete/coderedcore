#include "Action.hpp"
namespace CRE
{
    Action::Action(const std::string actionID, float durationInSeconds, bool useProgress) :
        _actionID(actionID),
        _duration(durationInSeconds),
        _progress(0),
        _use_progress(useProgress)
    {}

    Action::~Action()
    {}

    void Action::set_duration(float durationInSeconds)
    {
        _duration = durationInSeconds;
    }

    float Action::get_duration() const
    {
        return _duration;
    }

    float Action::get_progress() const
    {
        return _progress;
    }

    const std::string Action::get_ID() const
    {
        return _actionID;
    }

    bool Action::is_done() const
    {
        return _progress >= 1 and _use_progress;
    }

    void Action::reset()
    {
        _progress = 0;
    }

    void Action::do_action(Entity * theEntity, float timeElapsed)
    {
        _progress += (1 / _duration) * timeElapsed;
    }
}