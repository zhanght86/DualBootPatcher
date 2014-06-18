# Copyright (C) 2014  Xiao-Long Chen <chenxiaolong@cxl.epac.to>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import multiboot.config as config
import multiboot.fileio as fileio

FSTAB_REGEX = r'^(#.+)?(/dev/\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)'
EXEC_MOUNT = 'exec /sbin/busybox-static sh /init.multiboot.mounting.sh\n'


def modify_default_prop(cpiofile, partition_config):
    cpioentry = cpiofile.get_file('default.prop')
    if not cpioentry:
        return

    buf = cpioentry.content
    buf += fileio.encode('ro.patcher.patched=%s\n' % partition_config.id)
    buf += fileio.encode('ro.patcher.version=%s\n' % config.get_version())

    cpioentry.content = buf


def init(cpiofile, partition_config):
    modify_default_prop(cpiofile, partition_config)
