//cno_build_info.h: Runtime readable build information
/**
*	@file include/cno_build_info.h
*	@brief Runtime readable build information
*	@author Anadian
*	@license MIT License:
	Copyright 2017 Canosw
	Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, subject to the following 
conditions:
	The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CNO_BUILD_INFO_H
#define CNO_BUILD_INFO_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

/* CNO_FunctionName_[USC][ER](G) */

typedef struct CNO_Build_Info_struct{
	cno_u8_type build_string[CNO_BUFFER_MAXSIZE];
	cno_u8_type sdl_compiled[32];
	cno_u8_type sdl_linked[32];
	cno_u8_type sdl_image_compiled[32];
	cno_u8_type sdl_image_linked[32];
	cno_u8_type sdl_ttf_compiled[32];
	cno_u8_type sdl_ttf_linked[32];
	cno_u8_type sdl_mixer_compiled[32];
	cno_u8_type sdl_mixer_linked[32];
	cno_u8_type sdl_net_compiled[32];
	cno_u8_type sdl_net_linked[32];
	cno_u8_type pcre_compiled[32];
	cno_u8_type pcre_linked[32];
	cno_u8_type archive_compiled[32];
	cno_u8_type archive_linked[32];
} CNO_Build_Info_type;

/*
Three states: gameplay, cutscene, menu
Cutscenes must have letterboxing.
Loading screens must have a subtle progress bar (light glow from the bottom of the screen perhaps) and show a tip, status, and location/time.

HUD placement:
status:
name, level/lives, state
hp, bar-red, curent/max ±delta
/mp/stamina, bar-green, current/max ±delta //not Kirby
//ap acton-points?
//ep, bar-blue, current/max ±delta //not Kirby

EXP, purple-bar
GP, gold, current

[element]:off, minimal, standard (only for the HUD itself), comprehensive, custom
scaleable radius
12 slots
fade for HUD: auto, toggle, off
HUD: all always on, essentials on and fade rest, all fade, toggle, off
fade speed for elemant: fast, medium, slow.
Status (TL), game time/location/direction/weather (TC), Navigation/Alert (TR) connectivity and wall time
Mission info (tutorial hints),  (beacon), timers/splits 
count, reticle (multi-colour/monochrome/invisible), weapon info/equipment mapping 
hotkey (ally info), subtitles, controller state
Inventory/Command (BL), Contextual (BC), Enemy Info (BR)/picture-in-picture
[OSC]???

hint/tutorials: off, optional, automatic

Text engine, optionally, allows for: mustache-style variable lookups, inline markdown, and RTL.

AI:
Reaction 0-10
Accuracy(skill) 0-10
Knowledge 0-10 //2 points for mechanics, map, location, equipment, opponents
Priority lazy, vengeance, equalizer
Strategy methodical, statistical, oddball
Attention precise, general
Caution risky, safe	//stealth v aggression

NPC states: Neutral, Concerned, Aggressive, Friendly.
//Scared (not in kirby)

Map colours:
player green
allies blue
neutrals yellow
hostile red
unlocked and visited doors blue
unlocked and non-visited doors yellow
locked doors red
red exclamation mark primary objection
yellow exclamation mark secondary objectives
blue exclamation marks completed objects?
yellow question mark secrets non found
blue question marks secrets found
lighter background = higher ground
normal black
water cyan
lava red/pink
buildings brown/grey
Player character is an arrow with transulent arrows indicating previous locations.

Objectives symbols:
Notes screen [flowchart]
Diamond [horizontal line]: Required objective.
Square [Diagonal line]: Alternative objective; mutually exclusive branching paths.
Circle [vertical line]: Optional objective.
The fill of the icon indicates progress:
Solid: objective completed.
Half-full: objective pending.
Empty: objective failed.
Completed/failed objective are greyed out.
First time through a mission, objectives will be invisible until assigned by a quest giver.
When replaying a completed mission, all objectives will be shown regardless.
Objectives can have parent and child objectives, a reason, description, and a target

Game Menu:
Map
Inventory
Status
Notes/Logs/Media

Inventory:
Consumables
Equipment
Key Items
Materials

System Menu:
Resume
Retry from checkpoint
Save game
Load game
Achievements
Options
Extras
Multiplayer
//Screenshot
Restart mission
Abort Mission
Quit to desktop
Quit to title screen

Game Over screen:
Retry from checkpoint
Load game
Restart Mission
Abort Mission
Quit to Main Menu
Quit to Desktop

Main Menu:
Story Mode
Arcade Mode
Time Attack Mode
Challenge Mode
Practice Mode
Versus Mode
Party Mode
Online
Achievements
Extras
Options
Quit to Desktop

Achievements:
Achievements
Unlockables
Progress
Records
Statistics

Extras:
Documents
	Help
		Manual
		Glossary
		Tips
		Credits
		Changes
		Attributions
		License
	Encyclopedia 
		Characters
			Information
			Abilities
			Combat Statistics
		Locations
			Maps
			Info
			Discoveries
		Items
			Consumable
			Equipment
			Resources
			Key Items
		Logs
			Text Files
			Notes
			Transcripts
Pictures
Replays
Gallery (Animations/Cutscenes)
Soundtest
Leaderboards
DLC

Options:
Video
Audio
Input
Network
System
Text
Graphics
Sound
Controls
Camera
Interface
Gameplay

Display:
driver
display
display mode <WIDTH>x<HEIGHT>x<BITS_PER_PIXEL>@<REFRESH_RATE>
exclusive fullscreen
xoffset
yoffset
width
height
framerate
vsync
[borderless]
[[resizable]]
disable screensaver
software-to-hardware scale
scale-to-any-resolution, scale-to-nearest-aspect, no-scaling
[viewport scale if any or nearest-aspect]

Sound: (unless -A)
audio driver
audio device
master volume
master balance
gameplay volume
cutscene/media volume
menu volume
Event music
diagestic music
ui music
ambience
ui sound effects
weapon sound effects
player sound effects
diagestic sound effects
miscellaneous sound effects
[categorical muting]
voice language
dialog voice
barks and gameplay-relevant voice
chitchat voice
players voice
other players voice for mic chat
game menu volume reduction
channels
samplerate
3D sound (hardware accelerated)
sound-modifying effects
streaming preload
mic sensitivity

Text:
text language
delay
auto-scroll
wrapping to character, word, sentence
gameplay subtitles (lang)
font-size
format (colours)
cutscene subtitles (lang)
font-size
format
menu-text (lang)
font-size
format
ui-text (lang)
font-size
format

Input:
source toggles
key mode (scancode/keycode)
disable keyboard/mouse while controller connected
mouse mode (toggles for motion, buttons and wheels)
mouse sensitivity
mouse wheel inversion
touch mode (mouse/finger)
controller mode: 
xinput
joystick
[joystick deadzone]
[joystick peak]
[joystick rumble]
game-controller
libusb
libgamepad
soft pause for lack of input
devices

Camera:
disable mouse camera when controller connected
SOP (Side-on Perspective): sensitivity, speed.
TDP (Top-down Perspective): sensitivity, speed, distance?
Orbit (for melee): x/y-invert, sensitivity, speed, correction (off, minimal, modest, zealous), wall clipping, targeting
TPS (for projectile-weapons): x/y-invert, sensitivity, speed, wall clipping, targeting, aim-assist, distance?
Gallery: x/y-invert, sensitivity, speed, no-move-box width/height, move-box width/height, aim-assist
OTS (over-the-shoulder): x/y-invert, sensitivity, speed, aim-assist
FPS: x/y-invert, sensitivity, speed, aim-assist, FOV
ADS (aim-down-site): x/y-invert, sensitivity, speed, snap

//aim point
//view point
//rot point
Gameplay Controls:
LT: Aim(FPS)/Target(TPS)/Strafe-GunLock(2D ranged weapon)/Block(2D melee weapon)	RT: Shoot(Ranged weapon)/Block(Melees weapon)/Stationary-PositionLock(2D ranged weapon)/Block(2D Melee weapon)(or item?)
LB: Low Profile Mod (Sneak/Crouch)	RB: High Profile Mod (Force/Command)/Scanner-Binoculars/AuxilaryAction
Dpad (Weapons(Up/Down)/Inventory(Left/Right)/Stance/(hold) menus)
	Inventory		Select: GameMenu	Start: SystemMenu		Special
Status		Notes										Normal		ContextualAction
	Map															Jump
				L3: Run						R3: ChangeCamera (Scope/Scanner)
Menu Controls:
LT: Scroll Modifier		RT: Sort/Filter/View
LB: Pane Left			RB: Pane Right
																	Select
	DPAD: Change Selection		Drop/Default (Negative action/Quick Action)		Confirm (Positive action/(Hold) Menu)
																	Back/Cancel
														RSTICK: Free move?
													RUP: Quick Scroll up
		LSTICK: Change Selection			RLEFT: Subscreen left	RRIGHT: Subscreen Right
													RDOWN: Quick Scroll down
Game must require less-than-or-equal-to 16 buttons (plus 2 analogue sticks) while also remaining playable, if unoptimal, with just a dpad and 4 buttons.
Three-column, two-column, one-column with description, one-column no description
At most two columns of menu options: hold right to select all.
//Grid view?
Menu inputs along the button and top modal overlay.
GameMenu: Half volume: greyed transparent)
SystemMenu: Muted: Blacked out at least 90%.

Hold normal: stronger (heavy) melee
Hold special: buff/change ammo


Binoculars:
x10 optical zoom
two views: augmented and transparent
scanning and info
camera
controls:
			ZoomIn
TransparentView		AugmentedView
			ZoomOut

Network:
Online
Account
Encrypt save data

Graphics:
Gamma correction
Effects
Quality:
	Blood off/mild/maximum
	Gameplay/Cutscene Model/Texture quality for Player/Actor/Object/Environment/Shrubbery Very-Low/Low/Medium/High/Very-High
	Texture Effects duration short/medium/forever
	Shadow Quality
	Lighting Quality
	Reflection off/Quality
	Transparency Quality
	Post Effects //bloom, colour adjustments
	Despawn fade delay short/long/forever
	Particle effects low/med/high
	Draw Distance radius small/medium/large/infinite
	Draw-Distance quality-drop-off scale none/linear/exponential
	Texture scaling none/linear/bilinear/...
	Sprite flashes for spawn/damage/stat-effect off/monochromatic/transparency/coloured
Content
HUD

System:
autosave 
Save screenshot with each save game.
softpause on focus lost
Loading-and-freeing/memory usage, preload-everything, preload everything and free as needed, load as needed but don't free until quit, high/medium/low memory usage
Decompress game data
Mods

elements:
water //slow / douse
fire //burn / melt
ice //freeze / strengthen
wind //throw / throw/ware
earth //high damage / ground
electricity //crit / conduct
water

augments:
holy //strong against mystical / weak against realistic
dark //strong against realistic / weak against mystic
plasma //strong against
fungus
herbal

Properties:
s8 temperature
u8 sound
s8 light (positive emits light/negative is shadows)
s8 smell (good/bad)
u16 solidity (gas,plasma,fluid,soft,firm,hard)
u8 sharpness
u8 flexibility
u16 mass
u8 magnetism
u8 wetness
u8 refraction
u8 friction
u8 conductivity

Materials:
Dirt,
Sand,
Rock,
Metal,
Glass,

attack styles:
impale/penetrate //effective against biotic enemies and realistic enemies
slash/burn //all-around
bash/blunt //effective against mystical enemies and armored enemies
shoot //short, medium, long, penetration,
cast //AoE, persistence, homing?
throw //arc, variance, delay?

penetrate v. bash
speed v. power

Criticals deal x4 damage.

Elemental:±0.2
HP=(Level*100)
Attack=AttackStyle+(Level*Strength)+(WeaponDamage)
Defence=TargetState+(Level*Constitution)+(ArmorDefense)
Damage=(Attack*Elemental*(Attack/(Attack+Defence)))*critical
Wepon/Armor=0-400
actions:
run,
jump,
swim,
swing,
stab,
block,
aim/targetting?,
throw,
evade,
climb,
grab,
sneak,
cast/shoot,
hack (mechanical skill)
converse,
tinker,
sense,
react,
flex,
endure,
persuade,
bluff,

inquire
suggest
criticise
threaten
compliment
empathise
appeal
negotiate
bluff
jest
absolve
instruct


stats:

Character:
strength (swing, stab, block, throw, climb, grab) v. dexterity
constitution (HP, resistance, knockback) v. agility
intelligence (MP, magic, block, stab?, sneak, cast)
agility (EP, swing, throw, evade, climb, grab, sneak) //speed
dexterity (skill (SP), aim, hack, grab, block, climb, sneak) //reduction

Four-wheel vehicle:
Acceleration (strength)
Durability (constitution)
Boost (intelligence)
Top speed (agility)
Handling (dexerity)

Ship:
Attack power
Durability
Boost
Speed
Handling/aiming? //maybe

Projectile weapon:
Dammage
Penetration
Ammo
Speed/Rate of fire
Range

Melee weapon:
Damage
Penetration
Area
Speed
Duration/Technique //movement while swinging, cancelling, et cetera.

or

attack
defence
magic
mobility
reduction

strength/dexterity
constitution/agility
utility/mastery
combat/stealth
independent/collaborative 
technical/social
lawful/populist
idealist/realist
analytical/intuitive
stoical/emotional
rational/altruistic
secular/spiritual
competitive/cooperative

Next Level XP Requirement = ceiling(8*(1.225^CurrentLevel))
5 stats each with 10 skill levels.
Get 64 skill points per level.
Cost of obtaining a given skill level 2^SkillLevel

Player can customize, unequip, and equip everything including jump.
(Only at start of stage or at specific locations in an openworld setting.)
Customiziable to the input style: single press, double tap, hold

resources (social favours)
knowledge,

debuffs:
slow
burn/weaken
syphon
freeze
poison

rect: x:u32,y:u32,w:u16,h:u16
point: x:u32,y:u32
distance: x:s32,y:s32
cell: #:u16,x:f32/16,y:f32/16,
pixel: #:u16,x:u16,y:u16,R:u8,G:u8,B:u8
metre=16px*16px
set based on cells and points
map / spaces, tilesets / tiles, spritesheets / cells are all divided into .
sprite:
	static:
		type:u16,
		name,
		graphic:
			bitmap,
			cell:
				canvas:
					dimensions:rect
					collision:rect,
					hit:rects,
					hurt:rects,
					point,
				animation-delay,
				animation-next-cell
		sound:
			effects:
				sample,
				cell-links
		level,
		hp,
		sp, //suspicion for enemies
		ep,
		alignment,
		strength,
		constitution,
		intelligence,
		agility,
		dexterity,
		state,
		behaviour,
	dynamic:
		id:u16,
		state,
		cell,
		hp,
		sp,
		ep,
		mods:
			rotation,
			scale,
			colour,
		position,

Relative-to:
World
Room
Screen
Display

Statistics:
Starts (spawns, state, shoot),
Successes (kill, completed uninterrupted, hit)
Time,
Sum (if applicable; distance per character, damage per attack)
Failures (crashes, defeats, counters)
Players have statistics: not characters.
All-Time Total: //Actually saved.
	mode:
		stage
	character:
		state:
			attack
This session:
This stage (for scoring)
Medals:

Perfect: Take no damage. 4
Durable: Never heal. 1

Friend: Help your teammates. 2 REBALANCE TOMORROWvbb nnm
Independent: Depend on no allies. 1
Minimal: Use 'minimal' selected equipment. 1
Zeroest: Complete stage while depraved of any equipment or items. 3

Pacifist: Cause no harm. 4
Moral: No kills. 2
Psycho: Kill everyone. 3

Stealth: No alarms. 1
Ghost: No one even noticed you were there. 3

Instantaneous: Beat dev time. 3
Speedy: Beat par-time. 1
Combo: High combo. //Can combo corpse offset streak 1
Streak: Sustaining a long kill streak. 1
Efficiency: Kill multiple targets at once. 1

Sharp: Never miss. 1
Ascetic: Minimize collectibles and powerups. 1
Optimal: Complete the stage with as few button presses as possible. 3
Eloquent: Efficiency. 4

Collector: Find all hidden collectibles. 1
Methodical: Collect all items. 3

Adept: Succeed in all task skillfully. 2
Wheelman: Never crash a vehicle. 1
Stuntman: Cool stunts, bro. 2
Abiding: Abide the law. 2

Leader: Dominate the battlefield. 4
Inspirational: Get progressively better. 3
Volatile: Change place a lot. 1
Consistent: Hold your position. 1
Victim: It's just not fair. 1

Sensitive: Talk your way out of everything 2
Conversational: Talk to a lot of people. 2
Introvert: Talk to no one. 1

Foresight: Complete an objective before having it assigned. 1
Hardcore: No saves or checkpoints. 2
Completionist: Clear all objectives. 2

Utility: Meet the requirements for several medals in one play through. 1
Clever: Do something exceptionally clever. 1

FinalScore = sum(BaseScore,(BaseScore * (<FactorN>/4)) ...)
4+3+4+3+4+2+3+2+5+2=32

attack, element1 element2, DMG, stun, speed, super cost, super DMG, super stun, range (long medium short)
medium and long are weaker against heavy enemies; short range weapons deal less damage to far away targets
combos: start, hits, finish; low DMG high stun attacks start combo, high DMG low stun attacks finish combos
knockback is derived from damage
speed and stun are related

enemy, element1 element2, HP, class, EXP, gold

Damage varies depending on state and location; enemies are most vulnerable while preparing an attack.

Difficulty:
Easy: Recommended for novice players or content tourist. Base attack is doubled and defence is quadrupled. Strong regen is available early in the game. Miracles, criticals, item drops all in effect. Resource management is trivial.
Normal: Recommended for modern players. Criticals and item drops are in effect. Modest regen is available about halfway through the game. Resource management is recommend but not strictly necessary.
Hard: Recommended for action-RPG veterans accustom to old-school difficulty or people who have played the game before. Enemies are more plentiful and more aggressive. Bosses have more attacks. Weak regen is available late in the game. Only items are still in effect. Resource management is required.
Very Hard: Recommended for masters of the game. Like Hard mode except attack and defence are both halved, items cost more and there is no regen at all. Neither miracles, criticals, nor item drops are in effect. Optimal resource management is required. Not recommend for first playthroughs.
Impossible: A gimmick difficulty, this mode is like Very Hard except you die in one hit. Optimal resource management probably still won't be enough.

Gimmicks (for arcade mode):
Game Speed (0.5, 1, 2, 3, 4)
Set Lives (0 for permadeath)
Set Levelcap
Permanent Ailments
Require Medals
Enemy/Boss
	HP (Regen/Invincible)
	Visibility (Invisible, near, Projectiles?)
	Level Multiplier
Shuffle (enemies, rooms, bosses, abilities, items)


Save game must show in-game time, real-world save time, and preferably screenshot.
Three auto save slots (action/room/stage), three quick save slots, at least five hard save slots, one suspension save slot. per profile
Only host and official servers can record replays.
Host can only record offline games, up to four players.

Leaderboards for 
Completion time (single loop),
High score (single loop),
High score (multi loop),
Stages cleared (multi loop)

Characters (style);
Kirby (normal)
Metaknight (Metakinghtmare)
King Dedede (Brawling plus block breaking)
Broomhatter (Dust Force)
Marx (They Bleed Pixels)
Nnja (Return of the Ninja)
Plasma (Penta Pal)
*/

//DreamPuff-thing-major-minor-patch binary-x86_64-macOS-clang-branch-commit
//repo:package@version

cno_u8_type CNO_Build_Info_Init(CNO_Build_Info_type *build_info);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
