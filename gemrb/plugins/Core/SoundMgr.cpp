/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header: /data/gemrb/cvs2svn/gemrb/gemrb/gemrb/plugins/Core/SoundMgr.cpp,v 1.4 2004/08/09 13:02:08 divide Exp $
 *
 */

#include "SoundMgr.h"
#include "Ambient.h"

SoundMgr::SoundMgr(void)
{
}

SoundMgr::~SoundMgr(void)
{
}

void SoundMgr::AmbientMgr::activate(const std::string &name)
{
	for (std::vector<Ambient *>::iterator it = ambients.begin(); it != ambients.end(); ++it) {
		if ((*it) -> getName() == name) {
			(*it) -> setActive();
			break;
		}
	}
}

void SoundMgr::AmbientMgr::deactivate(const std::string &name)
{
	for (std::vector<Ambient *>::iterator it = ambients.begin(); it != ambients.end(); ++it) {
		if ((*it) -> getName() == name) {
			(*it) -> setInactive();
			break;
		}
	}
}

bool SoundMgr::AmbientMgr::isActive(const std::string &name) const
{
	for (std::vector<Ambient *>::const_iterator it = ambients.begin(); it != ambients.end(); ++it) {
		if ((*it) -> getName() == name) {
			return (*it) -> getFlags() & IE_AMBI_ENABLED;
		}
	}
	return false;
}
