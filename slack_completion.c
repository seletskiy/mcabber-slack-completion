#include <string.h>
#include <stdlib.h>

#include <mcabber/logprint.h>
#include <mcabber/modules.h>
#include <mcabber/settings.h>
#include <mcabber/compl.h>

static void slack_completion_init(void);
static void slack_completion_uninit(void);

module_info_t info_slack_completion = {
    .branch          = MCABBER_BRANCH,
    .api             = MCABBER_API_VERSION,
    .version         = "1.0",
    .description     = "Provides username autocompletion with @",
    .requires        = NULL,
    .init            = slack_completion_init,
    .uninit          = slack_completion_uninit,
    .next            = NULL,
};

static GSList *compl_dyn_resource_slack(void)
{
    GSList *buddies = buddy_getresources_locale(NULL);
    GSList *buddies_last = g_slist_last(buddies);
    GSList *buddy_pointer;

    buddies = g_slist_append(buddies, g_strdup("@channel"));
    buddies = g_slist_append(buddies, g_strdup("@everyone"));

    for (
        buddy_pointer = buddies;
        buddy_pointer != buddies_last;
        buddy_pointer = g_slist_next(buddy_pointer)
    ) {
        gchar *old_name = buddy_pointer->data;
        gchar *new_name = g_strdup_printf("@%s", old_name);
        buddies = g_slist_append(buddies, new_name);
    }

    return buddies;
}


static void slack_completion_init(void) {
    scr_log_print(LPRINT_NORMAL, "slack_completion: init");

    register_builtin_cat(COMPL_RESOURCE, compl_dyn_resource_slack);
}

static void slack_completion_uninit(void) {
}
