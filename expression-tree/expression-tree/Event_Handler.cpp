#ifndef _EVENT_HANDLER_CPP
#define _EVENT_HANDLER_CPP

#include "Event_Handler.h"

Event_Handler::~Event_Handler (void)
{
}

void
Event_Handler::delete_this (void)
{
  delete this;
}

#endif /* _EVENT_HANDLER_CP */
