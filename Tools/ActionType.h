#ifndef ACTIONPARTTYPE_ENUM_DECLARATION
#define ACTIONPARTTYPE_ENUM_DECLARATION

enum ActionType { UNVALID_ACTION     = 0,
									INITIALIZE_ACTION  = 1,
									SYNCHRONIZE_ACTION = 2,
									OPTIMIZE_ACTION    = 4,
									DUMPMESH_ACTION    = 8,
									WRITE_ACTION       = 16,
									COLLECT_ACTION     = 32
};

#endif // ACTIONPARTTYPE_ENUM_DECLARATION
