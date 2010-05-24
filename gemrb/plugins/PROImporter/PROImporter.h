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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 */

#ifndef PROIMPORTER_H
#define PROIMPORTER_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "ie_types.h"
#include "Projectile.h"
#include "ProjectileMgr.h"


class PROImporter : public ProjectileMgr {
private:
	DataStream* str;
	bool autoFree;
	int version;

public:
	PROImporter(void);
	~PROImporter(void);
	bool Open(DataStream* stream, bool autoFree = true);
	Projectile* GetProjectile(Projectile *s);
private:
	void GetAreaExtension(ProjectileExtension *s);
};


#endif
