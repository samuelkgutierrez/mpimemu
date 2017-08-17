#include "mpimcb-rt.h"

#include <cstdio>
#include <unistd.h>

/**
 *
 */
mmcb_rt::mmcb_rt(void)
{
    deactivate_all_mem_hooks();
}

/**
 *
 */
mmcb_rt::~mmcb_rt(void) = default;

/**
 *
 */
mmcb_rt *
mmcb_rt::the_mmcb_rt(void)
{
    static mmcb_rt singleton;
    return &singleton;
}

/**
 *
 */
mmcb_mem_hook_mgr_t *
mmcb_rt::get_mem_hook_mgr(void)
{
    return &mhmgr;
}

/**
 *
 */
void
mmcb_rt::activate_all_mem_hooks(void)
{
    mmcb_mem_hook_mgr_activate_all(&mhmgr);
}

/**
 *
 */
void
mmcb_rt::deactivate_all_mem_hooks(void)
{
    mmcb_mem_hook_mgr_deactivate_all(&mhmgr);
}

/**
 *
 */
mmcb_mem_hook_mgr_t *
mmcb_rt_get_mem_hook_mgr(void)
{
    return mmcb_rt::the_mmcb_rt()->get_mem_hook_mgr();
}