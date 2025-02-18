// SPDX-FileCopyrightText: 2023 Carl Zeiss Microscopy GmbH
//
// SPDX-License-Identifier: MIT

#pragma once

#include "BrickBaseInfo.h"
#include "DataTypes.h"
#include "IDataObj.h"
#include "IDatabaseTransaction.h"

namespace imgdoc2
{
    /// This interface is providing write access to a 3D-document.
    class IDocWrite3d : public imgdoc2::IDatabaseTransaction
    {
    public:
        /// Adds a brick to the document, and if successful, return its primary key.
        /// \param  coord        The coordinate.
        /// \param  info         The logical position information.
        /// \param  brickInfo     Information describing the brick.
        /// \param  datatype     The datatype.
        /// \param  storage_type Type of the storage.
        /// \param  data         The data.
        /// \returns If successful, the primary key of the newly added tile.
        virtual imgdoc2::dbIndex AddBrick(
            const imgdoc2::ITileCoordinate* coord,
            const imgdoc2::LogicalPositionInfo3D* info,
            const imgdoc2::BrickBaseInfo* brickInfo,
            imgdoc2::DataTypes datatype,
            imgdoc2::TileDataStorageType storage_type,
            const imgdoc2::IDataObjBase* data) = 0;

        ~IDocWrite3d() override = default;
    public:
        // no copy and no move (-> https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c21-if-you-define-or-delete-any-copy-move-or-destructor-function-define-or-delete-them-all )
        IDocWrite3d() = default;
        IDocWrite3d(const IDocWrite3d&) = delete;             // copy constructor
        IDocWrite3d& operator=(const IDocWrite3d&) = delete;  // copy assignment
        IDocWrite3d(IDocWrite3d&&) = delete;                  // move constructor
        IDocWrite3d& operator=(IDocWrite3d&&) = delete;       // move assignment
    };
}
