#ifndef _UAPI_LINUX_DEVLINK_H_
#define _UAPI_LINUX_DEVLINK_H_
#define DEVLINK_GENL_NAME "devlink"
#define DEVLINK_GENL_VERSION 1
enum devlink_command { DEVLINK_CMD_UNSPEC, __DEVLINK_CMD_MAX };
enum devlink_attr { DEVLINK_ATTR_UNSPEC, __DEVLINK_ATTR_MAX };
enum devlink_port_type { DEVLINK_PORT_TYPE_NOTSET, __DEVLINK_PORT_TYPE_MAX };
enum devlink_eswitch_mode { DEVLINK_ESWITCH_MODE_LEGACY, DEVLINK_ESWITCH_MODE_SWITCHDEV };
enum devlink_eswitch_inline_mode { DEVLINK_ESWITCH_INLINE_MODE_NONE };
enum devlink_eswitch_encap_mode { DEVLINK_ESWITCH_ENCAP_MODE_NONE };
#endif
