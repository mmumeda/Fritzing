/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2011 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 5675 $:
$Author: cohen@irascible.com $:
$Date: 2011-12-13 19:57:40 -0800 (Tue, 13 Dec 2011) $

********************************************************************/

#ifndef JUMPERITEM_H
#define JUMPERITEM_H

#include "paletteitem.h"

class JumperItem : public PaletteItem
{
	Q_OBJECT

public:
	JumperItem( ModelPart * modelPart, ViewIdentifierClass::ViewIdentifier,  const ViewGeometry & , long id, QMenu* itemMenu, bool doLabel); 
	~JumperItem();

    QPainterPath shape() const;
    QPainterPath hoverShape() const;
 	bool setUpImage(ModelPart* modelPart, ViewIdentifierClass::ViewIdentifier viewIdentifier, const LayerHash & viewLayers, ViewLayer::ViewLayerID, ViewLayer::ViewLayerSpec, bool doConnectors, LayerAttributes &, QString & error);
	void saveParams();
	void getParams(QPointF & pos, QPointF & c0, QPointF & c1);
	void resize(QPointF pos, QPointF c0, QPointF c1);
	void resize(QPointF p0, QPointF p1);   
	QSizeF footprintSize();
	QString retrieveSvg(ViewLayer::ViewLayerID viewLayerID, QHash<QString, QString> & svgHash, bool blackOnly, double dpi);
	bool getAutoroutable();
	void setAutoroutable(bool);
	class ConnectorItem * connector0();
	class ConnectorItem * connector1();
	bool hasCustomSVG();
	bool inDrag();
	void loadLayerKin( const LayerHash & viewLayers, ViewLayer::ViewLayerSpec);
	PluralType isPlural();
	void addedToScene(bool temporary);
	void rotateItem(double degrees);
	void calcRotation(QTransform & rotation, QPointF center, ViewGeometry &);
	QPointF dragOffset();
	void saveInstanceLocation(QXmlStreamWriter & streamWriter);
	bool hasPartNumberProperty();
	QRectF boundingRect() const;

protected:
	void resize();
	QString makeSvg(ViewLayer::ViewLayerID);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void resizeAux(double r0x, double r0y, double r1x, double r1y);
	void rotateEnds(QTransform & rotation, QPointF & tc0, QPointF & tc1); 
	QPointF calcPos(QPointF p0, QPointF p1);
	void initialResize(ViewIdentifierClass::ViewIdentifier);
	void paintHover(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void paintSelected(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
	void alignMe(JumperItem *, QPointF & p); 

protected:
	QPointer<ConnectorItem> m_dragItem;
	QPointer<ConnectorItem> m_connector0;
	QPointer<ConnectorItem> m_connector1;
	QPointer<ConnectorItem> m_otherItem;
	QPointF m_dragStartScenePos;
	QPointF m_dragStartThisPos;
	QPointF m_dragStartConnectorPos;
	QPointF m_dragStartCenterPos;
	QPointF m_otherPos;
	QPointF m_connectorTL;
	QPointF m_connectorBR;
	QPointF m_itemPos;
	QPointF m_itemC0;
	QPointF m_itemC1;
	QHash <ViewLayer::ViewLayerID, QPointer<FSvgRenderer> > m_renderers;
};

#endif
