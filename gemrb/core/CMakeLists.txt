ADD_DEFINITIONS(-DGEM_BUILD_DLL)

IF (ANDROID)
	set (PLATFORM_SRC System/Logger/Android.cpp)
ELSEIF (WIN32)
	set (PLATFORM_SRC System/Logger/Win32Console.cpp)
ELSE ()
	set (PLATFORM_SRC)
ENDIF ()

FILE(GLOB gemrb_core_LIB_SRCS
	ActorMgr.cpp
	Ambient.cpp
	AmbientMgr.cpp
	Animation.cpp
	AnimationFactory.cpp
	AnimationMgr.cpp
	ArchiveImporter.cpp
	Audio.cpp
	Bitmap.cpp
	Cache.cpp
	Calendar.cpp
	CharAnimations.cpp
	Compressor.cpp
	ControlAnimation.cpp
	Core.cpp
	DataFileMgr.cpp
	Dialog.cpp
	DialogHandler.cpp
	DialogMgr.cpp
	DisplayMessage.cpp
	EffectMgr.cpp
	EffectQueue.cpp
	Factory.cpp
	FactoryObject.cpp
	FileCache.cpp
	FontManager.cpp
	Game.cpp
	GameData.cpp
	GlobalTimer.cpp
	Image.cpp
	ImageFactory.cpp
	ImageMgr.cpp
	ImageWriter.cpp
	IndexedArchive.cpp
	IniSpawn.cpp
	Interface.cpp
	InterfaceConfig.cpp
	Inventory.cpp
	Item.cpp
	ItemMgr.cpp
	KeyMap.cpp
	LRUCache.cpp
	Map.cpp
	MapMgr.cpp
	MapReverb.cpp
	MoviePlayer.cpp
	MusicMgr.cpp
	Palette.cpp
	PalettedImageMgr.cpp
	Particles.cpp
	Plugin.cpp
	PluginLoader.cpp
	PluginMgr.cpp
	Polygon.cpp
	Projectile.cpp
	ProjectileMgr.cpp
	ProjectileServer.cpp
	Region.cpp
	Resource.cpp
	ResourceDesc.cpp
	ResourceManager.cpp
	ResourceSource.cpp
	SaveGameIterator.cpp
	SaveGameMgr.cpp
	ScriptEngine.cpp
	ScriptedAnimation.cpp
	SoundMgr.cpp
	Spell.cpp
	SpellMgr.cpp
	Spellbook.cpp
	Sprite2D.cpp
	SpriteCover.cpp
	Store.cpp
	StoreMgr.cpp
	StringMgr.cpp
	SymbolMgr.cpp
	TableMgr.cpp
	Tile.cpp
	TileMap.cpp
	TileMapMgr.cpp
	TileOverlay.cpp
	TileSetMgr.cpp
	Variables.cpp
	VEFObject.cpp
	Video.cpp
	WindowMgr.cpp
	WorldMap.cpp
	WorldMapMgr.cpp
	GameScript/Actions.cpp
	GameScript/GSUtils.cpp
	GameScript/GameScript.cpp
	GameScript/Matching.cpp
	GameScript/Objects.cpp
	GameScript/Triggers.cpp
	GUI/Button.cpp
	GUI/Console.cpp
	GUI/Control.cpp
	GUI/EventMgr.cpp
	GUI/GameControl.cpp
	GUI/Label.cpp
	GUI/MapControl.cpp
	GUI/Progressbar.cpp
	GUI/ScrollBar.cpp
	GUI/Slider.cpp
	GUI/TextArea.cpp
	GUI/TextEdit.cpp
	GUI/TextSystem/Font.cpp
	GUI/TextSystem/GemMarkup.cpp
	GUI/TextSystem/TextContainer.cpp
	GUI/Window.cpp
	GUI/WorldMapControl.cpp
	RNG.cpp
	Scriptable/Actor.cpp
	Scriptable/CombatInfo.cpp
	Scriptable/Container.cpp
	Scriptable/Door.cpp
	Scriptable/InfoPoint.cpp
	Scriptable/Scriptable.cpp
	Scriptable/PCStatStruct.cpp
	System/DataStream.cpp
	System/FileStream.cpp
	System/MappedFileMemoryStream.cpp
	System/MemoryStream.cpp
	System/Logger.cpp
	System/Logger/File.cpp
	System/Logger/MessageWindowLogger.cpp
	System/Logger/Stdio.cpp
	System/Logging.cpp
	System/SlicedStream.cpp
	System/String.cpp
	System/StringBuffer.cpp
	System/swab.c
	System/VFS.cpp
	${PLATFORM_SRC}
	)

IF(WIN32 AND HAVE_ICONV)
	SET(gemrb_core_LIB_SRCS
		${gemrb_core_LIB_SRCS}
		CodepageToIconv.cpp
		CodepageToIconvMap.cpp
	)
	INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})
ENDIF()

if (STATIC_LINK)
	ADD_LIBRARY(gemrb_core STATIC ${gemrb_core_LIB_SRCS})
else (STATIC_LINK)
	ADD_LIBRARY(gemrb_core SHARED ${gemrb_core_LIB_SRCS})
	TARGET_LINK_LIBRARIES(gemrb_core ${CMAKE_DL_LIBS} ${COREFOUNDATION_LIBRARY})
	IF (HAVE_ICONV)
		TARGET_LINK_LIBRARIES(gemrb_core ${ICONV_LIBRARY})
	ENDIF()
	IF(WIN32)
	  SET_TARGET_PROPERTIES(gemrb_core PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gemrb )
	  INSTALL(TARGETS gemrb_core RUNTIME DESTINATION ${LIB_DIR})
	ELSE(WIN32)
	  INSTALL(TARGETS gemrb_core LIBRARY DESTINATION ${LIB_DIR})
	ENDIF(WIN32)
endif (STATIC_LINK)

# make lintian happy
SET_TARGET_PROPERTIES(gemrb_core PROPERTIES
	VERSION "${GEMRB_VERSION}"
	SOVERSION "${GEMRB_VERSION}"
)

IF (APPLE)
	SET_TARGET_PROPERTIES(gemrb_core PROPERTIES
	INSTALL_NAME_DIR ${LIB_DIR}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gemrb/${PROJECT_NAME}.app/Contents/Frameworks
)
ENDIF (APPLE)
