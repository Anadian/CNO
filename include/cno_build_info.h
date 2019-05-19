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
Loading, screens must have a subtle progress bar (light glow from the bottom of the screen perhaps) and show a tip, status, and location/time.

Progress bar verbs:
Loading,
Saving,
Downloading,
Uploading,
Moving,
Copying,
Deleting

Progress bar format:
[Left-aligned] <VERB> <EntityA> [to <EntityB>]
[Centred] <Bar>
[Right-aligned] <LoadedBytes> / <TotalBytes> | <BytesPerSecond>

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
Status Bar: build info, version,  total frames in hexadecimal, frames per second, network, battery, realtime clock
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
Puncuation:
. neutral
.. distracted/drowsy/dazed
... unconsious 
' annoyed
'' agitated/agressive
''' enraged/frenzied
? suspicious
! alarmed
% scared
@ NPC, no new dialogue
* NPC with new dialogue
# NPC, not spoken too
& Ally
$ merchant
+ medic/service provider

Actor and dynamic object name and info format:
<IndexCode><Name><StateSymbol>

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

Mission: Independent, replayable, scored, resolve to either success or failure
Quest: Ambient, over-arching, stackable
Objectives symbols:
Notes screen [flowchart]
Lines represent actions; points represent world-states.
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
//Screenshot (Hold for capture mode.)
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
display mode <WIDTH>x<HEIGHT>x<BITS_PER_PIXEL>@<REFRESH_RATE> p: progressive i: interlaced c: checkerboard
exclusive fullscreen
xoffset
yoffset
width
height
framerate
framebuffers 0-3 (unbuffered, buffered, vsync, triple-buffered
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
include character names for dialogue
inlcude full closed captioning
visualise sound direction

Input:
mouse lock
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
LT: Aim(FPS)/Target(TPS)/Strafe-GunLock(2D ranged weapon)/Block(2D melee weapon)/Brake/Descend	RT: Shoot(Ranged weapon)/Block(Melees weapon)/Stationary-PositionLock(2D ranged weapon)/Block(2D Melee weapon)(or item?)/Accelerate/Ascend
LB: Low Profile Mod (Sneak/Crouch)	RB: High Profile Mod (Force/Command)/Scanner-Binoculars/AuxilaryAction
Dpad (Weapons(Up/Down)/Inventory(Left/Right)/Stance/(hold) menus)
													 ZoomIn			Select: GameMenu/Quick Map	Start: SystemMenu/(hold) Quick Restart		Special
												Weapons		MediaPlayer																	Normal		ContextualAction
													 ZoomOut																					Jump
				L3: Run/(Third Person LT+)Change Shoulder/(First Person LT+) Lean/(hold neutral) Fast Forward					R3: Scanner/(LT+)Scope/(hold) Altered Vision
Gently/gradual pressing LT: ADS without snap (ranged weapon), strafe without lockon targeting (melee)
Gently/gradually pressing RT: Hairtrigger ala Sniper Challenge (ranged weapon), Dyanamic stamina consumption for heavier, more-specialised attacks (melee)

Dpad_Left: Change between melee and ranged
Dpad_Left~: Holster/Weapon Sub Menu
Dpad_Right: Pause playing media
Dpad_Right~: MediaPlayer submenu
Dpad_Up: Zoom in
Dpad_Down: Zoom out
Jump+Jump: Glide
Glide+Aim: Bullet Time
Crouch+Movement+Jump: Dive
Dive+Aim: Bullet Time
Crouch+Sprint: Crouch Toggle
Aim+Scanner: Zoom
Aim(Third person)+Sprint: Change shoulder
Aim(First person)+Sprint: Lean
Aim+Action~: Bullet Time
Aim+Special: Reload
Aim+Special~: Change Ammo
ContextAction: Pickup
ContextAction~: Quick Consume

MediaPlayer submenu controls
A: Pause/Unpause
B: Stop
X: Repeat
Y: Shuffle
R1: Playlist Select (with R-stick)
R2: Fast-Foward
L2: Rewind
L1: Reset

Capture mode controls:
L2: Zoom Out			R2: Zoom In
L1: Effect-less view	R1: Capture
		Move Up													Effects/Filters menu
Roll Left	Roll Right	Technical Submenu	Return to Game	Hide UI		Comfrim
		Move Down												Cancel/return to menu
					Forward									camera
		Left	Reset Position	Right						R3: Reset angle
					Backwards
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
Three menu types:
	Fixed: Main Menu, Pause Menu
	Variable: File select, API select, user select.
	Dynamic: Inventory
Window Menu:
	File,
	Edit,
	View,
	Window,
	Help
//Grid view?
Menu inputs along the bottom and top modal overlay.
GameMenu: Half volume: greyed transparent)
SystemMenu: Muted: Blacked out at least 90%.

Game must include a launcher capable of downloading updates, and modifying settings with or without running the game.

Style guide:
	package-name
	DirectoryName (one-word names can be lower case)
	file_name.ext
	GLOBAL_STATICS
	GlobalFunctionsAndVariables
	propertiesAndMethods
	local_variables
	Variables are declared at the beginning of their scope.
	Indentation is done with tabs; one tab character for each level of indentation.
	Blocks start on the same line as their accompanying statement.
	At least one blank line between each function.
	C-style comments.


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
All assest have set priority parametres
instantances have each have a priority: [trivial|luxurious|recommended|important|essential]
Gamma correction
Effects:
	Density
	Complexity: [off/static|animated|simulated]
	Longevity
Water:
	Complexity
	World Reflections: [off|simple|dynamic]
	Object Reflections: [off|simple|dynamic]
	Reflection Resolution: VL/L/M/H/VH
	Light Refraction [off|simple|simulated]
	Coustics [off|animated|simulated]
	Splash [off|animated|simulated]
	Rubble Buoyancy: Boolean
	Bubbles: [off|animated|simulated]
	Proximity Effect [off|simple|simulated]
	Magnification [off|animated|simulated]
	Colour Distortion [off|simple|simulated]
Quality:
	Blood off/mild/maximum
	Gameplay/Cutscene Model/Texture quality for Player/Actor/Object/Environment/Shrubbery Very-Low/Low/Medium/High/Very-High
	Texture Effects duration short/medium/forever
	Dynamic Shadows off/partial/full
	Shadow Quality
	Dynamic Lighting Effects off/partial/full
	Dynamic Debris low/medium/high
	Reflections off/mimimal/maximum
	Reflection Quality
	Transparency Quality
	Post Effects //bloom, colour adjustments
	Despawn fade delay short/long/forever
	Particle effects low/med/high
	Rendering-Fog: Boolean
	Draw Distance radius small/medium/large/infinite
	(LOD bias) Draw-Distance quality-drop-off scale none/linear/exponential
	Texture scaling none/linear/bilinear/...
	Sprite flashes for spawn/damage/stat-effect off/monochromatic/transparency/coloured
	Dynamic Object indicators: particle emitters, sparkle, flash, reticle, et cetera.
Content
HUD

System:
autosave 
Save screenshot with each save game.
softpause on focus lost
mouselock
Loading-and-freeing/memory usage, preload-everything, preload everything and free as needed, load as needed but don't free until quit, high/medium/low memory usage
Decompress game data
Mods

A single universal store system, with shooping cart, capable of buying/selling items, buying unlockables, and DLC.
Outpost, fast travel points,  for starting missions, managing quest, picking up supplies, adjusting loadout.

elements:
water //slow / douse
fire //burn / melt
ice //freeze / strengthen
wind //throw / throw/ware/crack
earth //high damage / ground
electricity //crit / conduct
water
or:
fire (burns)
bio (controls)
wind/gas (wares)
rock (grounds)
electricity (is conducted)
water (douses)
fire

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
u8 flamable

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
direct/discrete

Next Level XP Requirement = ceiling(8*(1.225^CurrentLevel))
5 stats, each with 10 skill levels.
Get 64 skill points per level.
Cost of obtaining a given skill level 2^(SkillLevel-1)
This level 20*64=1280 skiil points for dedicated special skills.

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
tile: #:u16,x:f32/16,y:f32/16,
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
Region
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

Combat classes:
An army is comprised of 23-25 units of class:
Standard (7): all-arounder
Infiltrators (5): Small, fast, stealthy, low HP, ideal for capturing command post
Heavies (3): Slow, powerful, cannot operate vechiles, lots of HP, good for leading frontal assaults
Technician (3): Can repare machines and vechiles, set up traps (out of standard grenades) and one-way shields, if in the capture-zone while an enemy CP is caputred, will automatically repair the machines in the area
Sniper (2): Slow, good weapons, peerless accuracy, low HP, can be given information from "spotters"
Medic (1): Infinite medical supplies, very little offensive ability

Unconscious or fatally-wounded can be healed, executed, or detained.
Soldiers detained long enough will become captured or recruited (if heroicism is high enough)

Heroicism/Villianism:

Heroic acts:
healing allies/fatally-wounded enemies/neutral,
neutralising soldiers non-lethally,
repairing things,
sharing ammo,
disarming traps,
marking targets,

Hero perks:
Allies are more likely to heal you and share ammo with you;
Allies are motivated for longer when healed;
Captured enemies can be recruited to be allies;
Dying cause and area-of-effect Motivated-state for all nearby allies;
Stronger effect when capturing a neutral CP;
Score multiplier;

Hero detriments:
Notoriety, more information on you from a greater distance;
Halved effect of heroic acts;
Punished more harshly for villainous acts;

Neutral acts:
looting corpses;

Neutral perks:
Subtlety

Villainous acts:
Executing fatally-wounded and unconscious;
Friendly Fire, attacking allies;
Collateral Damage, harming neutrals and causing mass destruction;
Using fatally-wounded and unconscious as bait;
Using the deceased, unconscious, or neutrals as body shields;
Attacking medics;
Stealing ammo;

Villainous perks:
Devasting melee executions;
Stronger weapons;
Double the effect of heroic acts;
Halved effect of villainous acts;
Stronger effect when depleting the enemies' "grasp" of a CP;

Villainous detriments:
Ominous presence, detected and recognised from much farther away;
Allies are less likely to heal you, share ammo, or repair your vehicle;
Score reduction;

Status effects:
Refurbished, occurs when a machine/vehicle as been repaired from less than half HP to full HP, temporarily making the machine/vehicle twice as effective for allies of the technician that repaired.
Motivated, occurs when healing an ally with <50% HP to 100% HP, temporarily making them move and reload faster, and deal increased damage.
Unconscious, occurs when an actor is depleted of EP or asleep, regenerates health, takes double damage, and can be easily detained/executed.
Fatally-wounded, occurs when an actor's HP is less than 5%, cannot move or shoot, health slowly depletes, can be detained, executed, or healed.
Detained, occurs when an unconscious or fatally-wounded actors as been detained (cuffed), cannot do anything but be freed and healed by others, actor will become captured by the team that detained if not freed.
Burning, occurs when an actor is on fire, health quickly depletes until the fire is doused, patted out, or the actor is dead.
Poison, if not cured with an antidote with a set period of time, the actor will die immediately.
Suspicious, can be suspicious of non-player events (such as explosions and strange sounds).
Alerted,
Scared, occurs when soldiers are overwhelmed, more defensive, evasive, and generally less risky.
Invinciable: no damage can be taken.

Explosives:
Frag Grenade, high damage, high knockback, very loud; can be used to created, sticky, contact, proximity mines, claymore directional mines, and C4 remote mines.
Flame Grenade, inflicts burning, relatively quiet, proximity and remote variance.
Shock Grenade, no damage or knockback all stun, kind of loud, sticky, proximity, remote variance

Exposed plasma + water = combustion and self-destruction
Destroying enemy ships replenishes fuel.

Inventory quick-select sub-menu; starts on weapon
Attachments
Ammo
Weapon
Gear
Consumables
Equipment

Gear:
Regenerating Full-body Shield;
Regenerating Stealth Cloak;
Jetpack;
Directional Inifinite Shield;

Weapons:
Pistol: quiet, chargable, common; ammo: regular, tranquiliser, napalm
Assault Rifle: fast, loud, basic; ammo: regular, rubber.
Shotgun: wide cone, very inaccurate, good stopping power, really loud; reregular, combustion
Sniper Rifle: Peerless accuracy, penetration, damage, slow rate of fire, loud.
RPG Launcher: Very loud, very slow, massive destructive ability, peerless stopping power.
Crossbow: silent, slowish rate of fire, high damage, weak penetration.


Difficulty:
Easy (0.5): Recommended for novice players or content tourist. Base attack is doubled and defence is quadrupled. Strong regen is available early in the game. Miracles, criticals, item drops all in effect. Resource management is trivial.
Normal (1): Recommended for modern players. Criticals and item drops are in effect. Modest regen is available about halfway through the game. Resource management is recommend but not strictly necessary.
Hard (2): Recommended for action-RPG veterans accustom to old-school difficulty or people who have played the game before. Enemies are more plentiful and more aggressive. Bosses have more attacks. Weak regen is available late in the game. Only items are still in effect. Resource management is required.
Very Hard (4): Recommended for masters of the game. Like Hard mode except attack and defence are both halved, items cost more and there is no regen at all. Neither miracles, criticals, nor item drops are in effect. Optimal resource management is required. Not recommend for first playthroughs.
Impossible: A gimmick difficulty, this mode is like Very Hard except you die in one hit. Optimal resource management probably still won't be enough.
Custom:
Naviagtion
Combat
Stealth
Puzzles
Quick-Time Events
Tutorials

Navigation
Easy: Arrows appear to guide you to your destination; all collectibles automatically appear on the map; no "area-of-interest, only exact locations.
Normal: Destination are exact locations; collectibles are hidden until "discovered"; area-of-interest objective are kept comparatively small.
Hard: Objectives and collectibles  are all area-o-interest; all areas-of-interest are made larger.
Very Hard: No collectibles or objectives are shown on the map.

Combat
Refer to above; effects the multiplie on combat-related bonuses.

Stealth
Easy: Enemies are less observant and have simpler, more-predictable patterns.
Normal: is normal.
Hard: Enemies can notice more things; and have more complex adapting patterns; much better ar reporting things to a larger group; slightly more observant.
Very Hard: The AI is extremely perceptive; notices everything; and never let themselves go "radio dark."
Effects multiplier for stealth related bonuses.

Puzzles:
Easy: All puzzles can be skipped instantly.
Normal: Required puzzles can be skipped after a certain amount of time.
Hard: No puzzles can be skipped; puzzle are harder with randomised starting sets.
Very Hard: Puzzles cannot be skipped; all puzzle are significantly harder with procedural, indeterministic solutions.
Effects multiplier for time-related bonuses.

Quick-Time Events:
Easy: QTEs are easier and will be skipped, voiding any bonus, if failed.
Normal: Most quick-time events and still be properly failed.
Hard: QTEs requir slightly faster reflexes for a larger-completion bonus.
Very Hard: QTEs are significantly faster and more complex in nature; all QTEs must be passed to proceed.
Effects multiplier for QTE-success bonuses.

Tutorials:
Easy: Comprhensive tutorials
Normal: Reccomended tutorials.
Hard: Only essential tutorials.
Very Hard: No tutorials.

Difficulty is always dynamic on the first playthrough of the main mode.

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

Dynamic Log categories:
PlayerChat,NPCText,WorldEvents,SystemLogging

Save game must show in-game time, real-world save time, and preferably screenshot.
Three auto save slots (action/room/stage), two quick save slots, at least five hard save slots, one temporary suspension save slot. per profile
Only host and official servers can record replays.
Host can only record offline games, up to four players.

Leaderboards for 
Completion time (single loop),
High score (single loop),
High score (multi loop),
Stages cleared (multi loop)

Versus Multiplayer Mode Descriptors:
[1-4]xArmies | [1-4] Teams of four | [1-100] Fighters

Rule Set creator:
Exceed [X-Limit Below]-Limit response: Remove Player, End Game
Time Limit: 0 seconds to one hour;
Score Limit: 0 to infinity
Respawn Limit: 0 to 999
Kill Limit: 0 to 999
Captured-Flag Limit: 0 to 999
Command-Post Limit: 0 to 999
Winner Priority List
Loser Priority List
Match Sets: 1/1, 2/3, 3/5, 4/7, 5/9, 7/13, ... 50/99
Score Multipliers (Important)
Spawn Options: Boolean

Weapon Set:
Character-Spawn Optional limit: 0 for not available at character-spawn; X for limited ammounts; -1 for inifinite
Shared character-spawn-optional limit:Boolean
In-Level Spawn: Diasable; Consistent, competitive; random, party.
Mods and variability:
Min-Modifier: 
Max-Modifier:

Item Set: 
Character-Spawn Optional limit: Same as above
Shared limit
In-Level Spawn
Mods and variability

Vehicle Set:
Character-Spawn Optional PER-VEHICLE limit:
Shared limit
In-Level Spawn
Mods and variability

Character Set:
Character-Spawn Optional limit: Same as above
Shared limit
In-Level Spawn
Mods and variability
Location Set: 

SportBall:
LT: Aim RT: Shoot
LB: Defence RB: Lobb Pass
	X: Invest Dilation
y: Devest Dilation  A: Action 
	B: Jump

Characters (style);
Kirby (normal)
Metaknight (Metakinghtmare)
King Dedede (Brawling plus block breaking)
Broomhatter (Dust Force)
Marx (They Bleed Pixels)
Nnja (Return of the Ninja)
Plasma (Penta Pal)

Skills:
Skills can have 1-5 ranks; each rank has a cost matching a given level, for example:
Low HP Skill set: rank 1, level 2 cost (4 skill points), Last Gasp, Would-be fatal hits reduce your HP to 1; rank 2, level 5 cost (32 skill points), Desperation, increase attack and agility when <20% Max HP; rank 3, level 8 cost (256 skill points), Saving Throw, Score a kill with
Desperation: double attack at <10% HP.
Mortal Enbolding: double defence at less than 10% max HP.
Cunning Survival: double intellgence at less than 10% max HP.
Adrenaline: double agility at <10% HP.
Cool Under Pressure: double dexerity at <10% HP.
Last Gasp: Fatal hits will reduce you to 1 HP.
Second Wind: Scoring a kill when below 5% max HP will restore health to 15% max HP.	

Quest:
Playing with power: rebuilding rob.
Manifest Destiny: mediating integration.
No Truer Gentleman: Unweeded garden.
You're Answer Due: Robot procreation.
Proven Innocent: controversial trial.
New spec: newspeak for robots.
One Half of the Poor: Marxist troubles.
Halos: halo effect.
Fifth Business.
Found Wanting.
A Pack of Lies: agreed upon.
Bargaining: war.

*/

//DreamPuff-thing-major-minor-patch binary-x86_64-macOS-clang-branch-commit
//repo:package@version

cno_u8_type CNO_Build_Info_Create(CNO_Build_Info_type *build_info);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
