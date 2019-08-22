/*
 * Copyright 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef SDF_FRAME_HH_
#define SDF_FRAME_HH_

#include <string>
#include <ignition/math/Pose3.hh>
#include "sdf/Element.hh"
#include "sdf/Types.hh"
#include "sdf/system_util.hh"

namespace sdf
{
  // Forward declaration.
  class FramePrivate;
  class Geometry;

  /// \brief A Frame element descibes the properties associated with an
  /// explicit frame defined in a Model or World.
  class SDFORMAT_VISIBLE Frame
  {
    /// \brief Default constructor
    public: Frame();

    /// \brief Move constructor
    /// \param[in] _frame Frame to move.
    public: Frame(Frame &&_frame);

    /// \brief Destructor
    public: ~Frame();

    /// \brief Load the frame based on a element pointer. This is *not* the
    /// usual entry point. Typical usage of the SDF DOM is through the Root
    /// object.
    /// \param[in] _sdf The SDF Element pointer
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(ElementPtr _sdf);

    /// \brief Get the name of the frame.
    /// The name of the frame must be unique within the scope of its siblings.
    /// \return Name of the frame.
    public: std::string Name() const;

    /// \brief Set the name of the frame.
    /// The name of the frame must be unique within the scope of its siblings.
    /// \param[in] _name Name of the frame.
    public: void SetName(const std::string &_name) const;

    /// \brief Get the name of the coordinate frame to which this
    /// frame is attached. For an exThe interpretation of an empty value depends
    /// on the indicates that the frame is
    /// expressed relative to the attached-to link.
    /// \return The name of the attached-to frame.
    public: const std::string &AttachedTo() const;

    /// \brief Set the name of the coordinate frame to which this
    /// frame is attached. An empty value indicates that the frame is
    /// expressed relative to the attached-to link.
    /// \param[in] _frame The name of the attached-to frame.
    public: void SetAttachedTo(const std::string &_frame);

    /// \brief Get the pose of the frame object. This is the pose of the
    /// frame as specified in SDF
    /// (<frame><pose> ... </pose></frame>).
    /// \return The pose of the frame object.
    public: const ignition::math::Pose3d &Pose() const;

    /// \brief Set the pose of the frame object.
    /// \sa const ignition::math::Pose3d &Pose() const
    /// \param[in] _pose The pose of the frame object.
    public: void SetPose(const ignition::math::Pose3d &_pose);

    /// \brief Get the name of the coordinate frame relative to which this
    /// frame's pose is expressed. An empty value indicates that the frame is
    /// expressed relative to the attached-to link.
    /// \return The name of the relative-to frame.
    public: const std::string &PoseRelativeTo() const;

    /// \brief Set the name of the coordinate frame relative to which this
    /// frame's pose is expressed. An empty value indicates that the frame is
    /// expressed relative to the attached-to link.
    /// \param[in] _frame The name of the relative-to frame.
    public: void SetPoseRelativeTo(const std::string &_frame);

    /// \brief Get a pointer to the SDF element that was used during
    /// load.
    /// \return SDF element pointer. The value will be nullptr if Load has
    /// not been called.
    public: sdf::ElementPtr Element() const;

    /// \brief Private data pointer.
    private: FramePrivate *dataPtr = nullptr;
  };
}
#endif