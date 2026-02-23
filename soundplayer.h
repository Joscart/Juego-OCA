#pragma once

#include <QCoreApplication>
#include <QSoundEffect>
#include <QUrl>

/**
 * @brief Utilidad para reproducir sonidos cortos de forma fire-and-forget.
 *
 * Reemplaza el uso de QSound::play() que fue eliminado en Qt 6.
 * Los objetos QSoundEffect se autodestruyen al finalizar la reproducción.
 */
namespace SoundPlayer {

inline void play(const QString &resourcePath, qreal volume = 1.0)
{
    auto *effect = new QSoundEffect(QCoreApplication::instance());
    effect->setSource(QUrl("qrc" + resourcePath));
    effect->setVolume(volume);

    QObject::connect(effect, &QSoundEffect::playingChanged, effect, [effect]() {
        if (!effect->isPlaying()) {
            effect->deleteLater();
        }
    });
    QObject::connect(effect, &QSoundEffect::statusChanged, effect, [effect]() {
        if (effect->status() == QSoundEffect::Error) {
            effect->deleteLater();
        }
    });

    effect->play();
}

} // namespace SoundPlayer
