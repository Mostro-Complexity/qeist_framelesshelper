/*
 * MIT License
 *
 * Copyright (C) 2022 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "framelesswidget.h"
#include "framelesswidgetshelper.h"

FRAMELESSHELPER_BEGIN_NAMESPACE

FramelessWidget::FramelessWidget(QWidget *parent, const Options options) : QWidget(parent)
{
    m_helper.reset(new FramelessWidgetsHelper(this, options));
}

FramelessWidget::~FramelessWidget() = default;

bool FramelessWidget::isNormal() const
{
    return m_helper->isNormal();
}

bool FramelessWidget::isZoomed() const
{
    return m_helper->isZoomed();
}

void FramelessWidget::setTitleBarWidget(QWidget *widget)
{
    m_helper->setTitleBarWidget(widget);
}

QWidget *FramelessWidget::titleBarWidget() const
{
    return m_helper->titleBarWidget();
}

void FramelessWidget::setContentWidget(QWidget *widget)
{
    m_helper->setContentWidget(widget);
}

QWidget *FramelessWidget::contentWidget() const
{
    return m_helper->contentWidget();
}

void FramelessWidget::setHitTestVisible(QWidget *widget, const bool visible)
{
    m_helper->setHitTestVisible(widget, visible);
}

void FramelessWidget::toggleMaximized()
{
    m_helper->toggleMaximized();
}

void FramelessWidget::changeEvent(QEvent *event)
{
    QWidget::changeEvent(event);
    m_helper->changeEventHandler(event);
}

void FramelessWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    m_helper->paintEventHandler(event);
}

void FramelessWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    m_helper->mousePressEventHandler(event);
}

void FramelessWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    m_helper->mouseReleaseEventHandler(event);
}

void FramelessWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
    m_helper->mouseDoubleClickEventHandler(event);
}

FRAMELESSHELPER_END_NAMESPACE