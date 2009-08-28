/* desktop session recorder
 * Copyright (C) 2009 Benjamin Otte <otte@gnome.org
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "byzanzencoder.h"

#include <gst/gst.h>
#include <gst/app/gstappsrc.h>

#ifndef __HAVE_BYZANZ_ENCODER_OGG_H__
#define __HAVE_BYZANZ_ENCODER_OGG_H__

typedef struct _ByzanzEncoderOgv ByzanzEncoderOgv;
typedef struct _ByzanzEncoderOgvClass ByzanzEncoderOgvClass;

#define BYZANZ_TYPE_ENCODER_OGG                    (byzanz_encoder_ogv_get_type())
#define BYZANZ_IS_ENCODER_OGG(obj)                 (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BYZANZ_TYPE_ENCODER_OGG))
#define BYZANZ_IS_ENCODER_OGG_CLASS(klass)         (G_TYPE_CHECK_CLASS_TYPE ((klass), BYZANZ_TYPE_ENCODER_OGG))
#define BYZANZ_ENCODER_OGG(obj)                    (G_TYPE_CHECK_INSTANCE_CAST ((obj), BYZANZ_TYPE_ENCODER_OGG, ByzanzEncoderOgv))
#define BYZANZ_ENCODER_OGG_CLASS(klass)            (G_TYPE_CHECK_CLASS_CAST ((klass), BYZANZ_TYPE_ENCODER_OGG, ByzanzEncoderOgvClass))
#define BYZANZ_ENCODER_OGG_GET_CLASS(obj)          (G_TYPE_INSTANCE_GET_CLASS ((obj), BYZANZ_TYPE_ENCODER_OGG, ByzanzEncoderOgvClass))

struct _ByzanzEncoderOgv {
  ByzanzEncoder         encoder;

  cairo_surface_t *     surface;        /* last surface pushed down the pipeline */
  GTimeVal              start_time;     /* timestamp of first image */

  GstElement *          pipeline;       /* The pipeline */
  GstAppSrc *           src;            /* the source we feed with images */
  GstCaps *             caps;           /* caps of video stream */
};

struct _ByzanzEncoderOgvClass {
  ByzanzEncoderClass    encoder_class;
};

GType		byzanz_encoder_ogv_get_type		(void) G_GNUC_CONST;


#endif /* __HAVE_BYZANZ_ENCODER_OGG_H__ */
