#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "keystroke.h"
#include "model.h"
#include "QPainter"
#include "soundeffect.h"
#include <QSoundEffect>
//#include <QMediaPlayer>
#include <QtMultimedia>


QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

public:
    View(Model &model, QWidget *parent = nullptr);
    ~View();

signals:
    void keyPressed(KeyStroke key);

public slots:
    void updateFrame(QPixmap frame);
    void loopAudio();
    void playSoundEffect(SoundEffect sound);

private:
    Ui::View *ui;

    QSize gameSize;

    QMediaPlayer *music;
    QAudioOutput *output;

    QSoundEffect* dig;

    QSoundEffect* walk;
    QSoundEffect* findBone;
    QSoundEffect* door;
    QSoundEffect* shovel;
    QSoundEffect* brush;
    QSoundEffect* pageTurn;
    QSoundEffect* correct;
    QSoundEffect* wrong;
    QSoundEffect* victory;

    QMap<SoundEffect, QSoundEffect*> soundEffects;
};
#endif // VIEW_H
