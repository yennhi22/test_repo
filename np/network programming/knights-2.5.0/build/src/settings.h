// This file is generated by kconfig_compiler from knights.kcfg.
// All changes you do to this file will be lost.
#ifndef SETTINGS_H
#define SETTINGS_H

#include <kconfigskeleton.h>
#include <kdebug.h>

class Settings : public KConfigSkeleton
{
  public:
    class EnumAnimationSpeed
    {
      public:
      enum type { Instant, Fast, Normal, Slow, COUNT };
    };
    class EnumBorderDisplayType
    {
      public:
      enum type { None, Border, Notation, COUNT };
    };
    class EnumPlayer1Protocol
    {
      public:
      enum type { Local, XBoard, COUNT };
    };
    class EnumPlayer2Protocol
    {
      public:
      enum type { Local, XBoard, Fics, COUNT };
    };
    class EnumColor
    {
      public:
      enum type { NoColor, White, Black, COUNT };
    };

    static Settings *self();
    ~Settings();

    /**
      Set Theme file for the board
    */
    static
    void setTheme( const QString & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "Theme" ) ))
        self()->mTheme = v;
    }

    /**
      Get Theme file for the board
    */
    static
    QString theme()
    {
      return self()->mTheme;
    }

    /**
      Set whether to show a confirmation dialog before discarding game history
    */
    static
    void setAskDiscard( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "askDiscard" ) ))
        self()->mAskDiscard = v;
    }

    /**
      Get whether to show a confirmation dialog before discarding game history
    */
    static
    bool askDiscard()
    {
      return self()->mAskDiscard;
    }

    /**
      Set internal variable controlling the confirm dialog
    */
    static
    void setDontAskInternal( const QString & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "dontAskInternal" ) ))
        self()->mDontAskInternal = v;
    }

    /**
      Get internal variable controlling the confirm dialog
    */
    static
    QString dontAskInternal()
    {
      return self()->mDontAskInternal;
    }

    /**
      Set Moves animation speed
    */
    static
    void setAnimationSpeed( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "animationSpeed" ) ))
        self()->mAnimationSpeed = v;
    }

    /**
      Get Moves animation speed
    */
    static
    int animationSpeed()
    {
      return self()->mAnimationSpeed;
    }

    /**
      Set whether the Board is animated during rotating and resizing
    */
    static
    void setAnimateBoard( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "animateBoard" ) ))
        self()->mAnimateBoard = v;
    }

    /**
      Get whether the Board is animated during rotating and resizing
    */
    static
    bool animateBoard()
    {
      return self()->mAnimateBoard;
    }

    /**
      Set whether to rotate the board when in local two-player mode
    */
    static
    void setFlipBoard( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "flipBoard" ) ))
        self()->mFlipBoard = v;
    }

    /**
      Get whether to rotate the board when in local two-player mode
    */
    static
    bool flipBoard()
    {
      return self()->mFlipBoard;
    }

    /**
      Set chessboard border type
    */
    static
    void setBorderDisplayType( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "borderDisplayType" ) ))
        self()->mBorderDisplayType = v;
    }

    /**
      Get chessboard border type
    */
    static
    int borderDisplayType()
    {
      return self()->mBorderDisplayType;
    }

    /**
      Set show check marker
    */
    static
    void setShowDanger( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showDanger" ) ))
        self()->mShowDanger = v;
    }

    /**
      Get show check marker
    */
    static
    bool showDanger()
    {
      return self()->mShowDanger;
    }

    /**
      Set show legal moves marker
    */
    static
    void setShowMarker( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showMarker" ) ))
        self()->mShowMarker = v;
    }

    /**
      Get show legal moves marker
    */
    static
    bool showMarker()
    {
      return self()->mShowMarker;
    }

    /**
      Set show opponents move marker
    */
    static
    void setShowMotion( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showMotion" ) ))
        self()->mShowMotion = v;
    }

    /**
      Get show opponents move marker
    */
    static
    bool showMotion()
    {
      return self()->mShowMotion;
    }

    /**
      Set show clocks when time control is in use
    */
    static
    void setShowClock( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showClock" ) ))
        self()->mShowClock = v;
    }

    /**
      Get show clocks when time control is in use
    */
    static
    bool showClock()
    {
      return self()->mShowClock;
    }

    /**
      Set show chat window, if supported by the protocol
    */
    static
    void setShowChat( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showChat" ) ))
        self()->mShowChat = v;
    }

    /**
      Get show chat window, if supported by the protocol
    */
    static
    bool showChat()
    {
      return self()->mShowChat;
    }

    /**
      Set show the text console, if supported by the protocol
    */
    static
    void setShowConsole( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showConsole" ) ))
        self()->mShowConsole = v;
    }

    /**
      Get show the text console, if supported by the protocol
    */
    static
    bool showConsole()
    {
      return self()->mShowConsole;
    }

    /**
      Set show move history
    */
    static
    void setShowHistory( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "showHistory" ) ))
        self()->mShowHistory = v;
    }

    /**
      Get show move history
    */
    static
    bool showHistory()
    {
      return self()->mShowHistory;
    }

    /**
      Set initial time limit for both players
    */
    static
    void setTimeLimit( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "timeLimit" ) ))
        self()->mTimeLimit = v;
    }

    /**
      Get initial time limit for both players
    */
    static
    int timeLimit()
    {
      return self()->mTimeLimit;
    }

    /**
      Set time increment per move (for Incremental time control)
    */
    static
    void setTimeIncrement( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "timeIncrement" ) ))
        self()->mTimeIncrement = v;
    }

    /**
      Get time increment per move (for Incremental time control)
    */
    static
    int timeIncrement()
    {
      return self()->mTimeIncrement;
    }

    /**
      Set the number of moves the player has to make in the specified time (for Conventional time control)
    */
    static
    void setNumberOfMoves( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "numberOfMoves" ) ))
        self()->mNumberOfMoves = v;
    }

    /**
      Get the number of moves the player has to make in the specified time (for Conventional time control)
    */
    static
    int numberOfMoves()
    {
      return self()->mNumberOfMoves;
    }

    /**
      Set whether time limits are enabled and displayed
    */
    static
    void setTimeEnabled( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "timeEnabled" ) ))
        self()->mTimeEnabled = v;
    }

    /**
      Get whether time limits are enabled and displayed
    */
    static
    bool timeEnabled()
    {
      return self()->mTimeEnabled;
    }

    /**
      Set protocol to be used for player 1
    */
    static
    void setPlayer1Protocol( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "player1Protocol" ) ))
        self()->mPlayer1Protocol = v;
    }

    /**
      Get protocol to be used for player 1
    */
    static
    int player1Protocol()
    {
      return self()->mPlayer1Protocol;
    }

    /**
      Set protocol to be used for player 1
    */
    static
    void setPlayer2Protocol( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "player2Protocol" ) ))
        self()->mPlayer2Protocol = v;
    }

    /**
      Get protocol to be used for player 1
    */
    static
    int player2Protocol()
    {
      return self()->mPlayer2Protocol;
    }

    /**
      Set the local human player's color in a game against a computer or over the Internet.
    */
    static
    void setColor( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "color" ) ))
        self()->mColor = v;
    }

    /**
      Get the local human player's color in a game against a computer or over the Internet.
    */
    static
    int color()
    {
      return self()->mColor;
    }

    /**
      Set list of programs to run for playing against the computer
    */
    static
    void setPrograms( const QStringList & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "programs" ) ))
        self()->mPrograms = v;
    }

    /**
      Get list of programs to run for playing against the computer
    */
    static
    QStringList programs()
    {
      return self()->mPrograms;
    }

    /**
      Set the last selected program for player 1
    */
    static
    void setPlayer1Program( const QString & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "player1Program" ) ))
        self()->mPlayer1Program = v;
    }

    /**
      Get the last selected program for player 1
    */
    static
    QString player1Program()
    {
      return self()->mPlayer1Program;
    }

    /**
      Set the last selected program for player 2
    */
    static
    void setPlayer2Program( const QString & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "player2Program" ) ))
        self()->mPlayer2Program = v;
    }

    /**
      Get the last selected program for player 2
    */
    static
    QString player2Program()
    {
      return self()->mPlayer2Program;
    }

    /**
      Set the search depth of computer engines, when the difficulty is set to Configurable
    */
    static
    void setComputerSearchDepth( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "computerSearchDepth" ) ))
        self()->mComputerSearchDepth = v;
    }

    /**
      Get the search depth of computer engines, when the difficulty is set to Configurable
    */
    static
    int computerSearchDepth()
    {
      return self()->mComputerSearchDepth;
    }

    /**
      Set the memory size used by computer engines, when the difficulty is set to Configurable
    */
    static
    void setComputerMemorySize( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "computerMemorySize" ) ))
        self()->mComputerMemorySize = v;
    }

    /**
      Get the memory size used by computer engines, when the difficulty is set to Configurable
    */
    static
    int computerMemorySize()
    {
      return self()->mComputerMemorySize;
    }

    /**
      Set list of servers for playing over the Internet
    */
    static
    void setServers( const QStringList & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "servers" ) ))
        self()->mServers = v;
    }

    /**
      Get list of servers for playing over the Internet
    */
    static
    QStringList servers()
    {
      return self()->mServers;
    }

    /**
      Set the last selected server
    */
    static
    void setCurrentServer( const QString & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "currentServer" ) ))
        self()->mCurrentServer = v;
    }

    /**
      Get the last selected server
    */
    static
    QString currentServer()
    {
      return self()->mCurrentServer;
    }

    /**
      Set username for the Free Internet Chess Server
    */
    static
    void setFicsUsername( const QString & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "ficsUsername" ) ))
        self()->mFicsUsername = v;
    }

    /**
      Get username for the Free Internet Chess Server
    */
    static
    QString ficsUsername()
    {
      return self()->mFicsUsername;
    }

    /**
      Set whether to log in as guest
    */
    static
    void setGuest( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "guest" ) ))
        self()->mGuest = v;
    }

    /**
      Get whether to log in as guest
    */
    static
    bool guest()
    {
      return self()->mGuest;
    }

    /**
      Set whether to log in to chess server automatically
    */
    static
    void setAutoLogin( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "autoLogin" ) ))
        self()->mAutoLogin = v;
    }

    /**
      Get whether to log in to chess server automatically
    */
    static
    bool autoLogin()
    {
      return self()->mAutoLogin;
    }

    /**
      Set delay before a computer's move is reported, in milliseconds
    */
    static
    void setComputerDelay( int v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "computerDelay" ) ))
        self()->mComputerDelay = v;
    }

    /**
      Get delay before a computer's move is reported, in milliseconds
    */
    static
    int computerDelay()
    {
      return self()->mComputerDelay;
    }

    /**
      Set stored configurations of engine-specific settings
    */
    static
    void setEngineConfigurations( const QStringList & v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "engineConfigurations" ) ))
        self()->mEngineConfigurations = v;
    }

    /**
      Get stored configurations of engine-specific settings
    */
    static
    QStringList engineConfigurations()
    {
      return self()->mEngineConfigurations;
    }

    /**
      Set whether opponents' moves are spoken by Jovie
    */
    static
    void setSpeakOpponentsMoves( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "speakOpponentsMoves" ) ))
        self()->mSpeakOpponentsMoves = v;
    }

    /**
      Get whether opponents' moves are spoken by Jovie
    */
    static
    bool speakOpponentsMoves()
    {
      return self()->mSpeakOpponentsMoves;
    }

    /**
      Set whether commands over D-Bus are accepted
    */
    static
    void setAllowExternalControl( bool v )
    {
      if (!self()->isImmutable( QString::fromLatin1( "allowExternalControl" ) ))
        self()->mAllowExternalControl = v;
    }

    /**
      Get whether commands over D-Bus are accepted
    */
    static
    bool allowExternalControl()
    {
      return self()->mAllowExternalControl;
    }

  protected:
    Settings();
    friend class SettingsHelper;


    // KGameTheme
    QString mTheme;

    // Notification Messages
    bool mAskDiscard;
    QString mDontAskInternal;

    // Preferences
    int mAnimationSpeed;
    bool mAnimateBoard;
    bool mFlipBoard;
    int mBorderDisplayType;
    bool mShowDanger;
    bool mShowMarker;
    bool mShowMotion;
    bool mShowClock;
    bool mShowChat;
    bool mShowConsole;
    bool mShowHistory;

    // Time Control
    int mTimeLimit;
    int mTimeIncrement;
    int mNumberOfMoves;
    bool mTimeEnabled;

    // Protocols
    int mPlayer1Protocol;
    int mPlayer2Protocol;
    int mColor;
    QStringList mPrograms;
    QString mPlayer1Program;
    QString mPlayer2Program;
    int mComputerSearchDepth;
    int mComputerMemorySize;
    QStringList mServers;
    QString mCurrentServer;
    QString mFicsUsername;
    bool mGuest;
    bool mAutoLogin;
    int mComputerDelay;
    QStringList mEngineConfigurations;

    // Accessibility
    bool mSpeakOpponentsMoves;
    bool mAllowExternalControl;

  private:
};

#endif

